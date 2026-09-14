<?php
// Bounded, read-only adapter for the active ManTech module's diagnostic records.
// Deliberately does not read runtime credentials or invoke game commands.
function pb_tail(string $path, int $limit): string
{
    $file = @fopen($path, 'rb');
    if (!$file) return '';
    $size = fstat($file)['size'];
    $offset = max(0, $size - $limit);
    fseek($file, $offset);
    if ($offset > 0) fgets($file); // discard a potentially truncated first record
    $text = stream_get_contents($file, $limit);
    fclose($file);
    if (!is_string($text)) return '';
    $end = strrpos($text, "\n");
    return $end === false ? '' : substr($text, 0, $end + 1);
}

function pb_fields(string $text): array
{
    preg_match_all('/([a-zA-Z_][a-zA-Z_0-9]*)=(?:"([^"]*)"|([^\s]+))/', $text, $matches, PREG_SET_ORDER);
    $fields = array();
    foreach ($matches as $match) {
        $value = isset($match[3]) && $match[3] !== '' ? $match[3] : $match[2];
        $fields[$match[1]] = is_numeric($value) ? 0 + $value : $value;
    }
    return $fields;
}

function pb_parse(string $text): array
{
    $result = array('session' => null, 'history' => array(), 'latest' => null, 'population' => null);
    $batch = null;
    foreach (explode("\n", $text) as $line) {
        if (!preg_match('/^(\d{4}-\d\d-\d\d \d\d:\d\d:\d\d) PB_DIAG_(\w+) (.*)$/', $line, $match)) continue;
        list(, $stamp, $kind, $payload) = $match;
        if ($kind === 'SESSION') {
            $result = array('session' => array('timestamp' => $stamp, 'settings' => pb_fields($payload)), 'history' => array(), 'latest' => null, 'population' => null);
            $batch = null;
        } elseif ($kind === 'STATE') {
            $batch = array('timestamp' => $stamp, 'state' => pb_fields($payload), 'failures' => array());
        } elseif ($batch !== null && in_array($kind, array('ENGINE', 'MANAGER', 'CACHE', 'FAILURE'), true) && $stamp === $batch['timestamp']) {
            if ($kind === 'FAILURE') $batch['failures'][] = pb_fields($payload);
            else $batch[strtolower($kind)] = pb_fields($payload);
            // Publish only complete scalar groups. Optional failure rows can follow.
            if (isset($batch['engine'], $batch['manager'], $batch['cache'])) {
                $result['history'][$stamp] = array('timestamp' => $stamp, 'state' => $batch['state']);
                $result['latest'] = $batch;
            }
        } elseif ($kind === 'POP' && $batch !== null && $result['latest'] !== null) {
            $data = json_decode($payload, true);
            if (is_array($data)) $result['population'] = array('timestamp' => $stamp, 'data' => $data);
        }
    }
    $result['history'] = array_slice(array_values($result['history']), -120);
    return $result;
}

function pb_combat(string $text, ?string $session): array
{
    $result = array('timestamp' => null, 'settings' => array(), 'counts' => array(), 'traces' => array());
    foreach (explode("\n", $text) as $line) {
        if (!preg_match('/^(\d{4}-\d\d-\d\d \d\d:\d\d:\d\d) PB_COMBAT_(\w+) (.*)$/', $line, $match)) continue;
        list(, $stamp, $kind, $payload) = $match;
        if ($session !== null && $stamp < $session) continue;
        if ($kind === 'WINDOW') $result = array('timestamp' => $stamp, 'settings' => pb_fields($payload), 'counts' => array(), 'traces' => array());
        elseif ($stamp === $result['timestamp'] && $kind === 'COUNT') $result['counts'][] = pb_fields($payload);
        elseif ($stamp === $result['timestamp'] && $kind === 'TRACE') $result['traces'][] = pb_fields($payload);
    }
    usort($result['counts'], function ($a, $b) { return ($b['count'] ?? 0) <=> ($a['count'] ?? 0); });
    $result['counts'] = array_slice($result['counts'], 0, 60);
    $result['traces'] = array_slice($result['traces'], -60);
    return $result;
}

function mantech_bot_diagnostics(): array
{
    $root = dirname(__DIR__, 2) . '/turtle/logs/';
    $result = pb_parse(pb_tail($root . 'PlayerbotDiagnostics.log', 2097152));
    $stamp = $result['latest']['timestamp'] ?? null;
    $zone = new DateTimeZone('America/Chicago'); // local server's log clock
    $date = $stamp ? DateTimeImmutable::createFromFormat('!Y-m-d H:i:s', $stamp, $zone) : false;
    $age = $date ? max(0, time() - $date->getTimestamp()) : null;
    $interval = $result['latest']['state']['interval_ms'] ?? 30000;
    $result['available'] = $result['latest'] !== null;
    $result['online'] = realm_online(8088);
    $result['ageSeconds'] = $age;
    $result['stale'] = !$result['online'] || $age === null || $age > max(90, $interval / 1000 * 3);
    $result['source'] = 'ManTech Playerbots';
    $names = json_decode(@file_get_contents(__DIR__ . '/turtle-zone-names.json') ?: '{}', true);
    $result['zoneNames'] = array();
    foreach (($result['population']['data']['zones'] ?? array()) as $id => $count) {
        if (isset($names[$id])) $result['zoneNames'][$id] = $names[$id];
    }
    $result['combat'] = pb_combat(pb_tail($root . 'PlayerbotCombat.log', 1048576), $result['session']['timestamp'] ?? null);
    return $result;
}
