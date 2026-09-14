<?php
require __DIR__ . '/mantech-bot-diagnostics.php';
function check($condition, $name) { if (!$condition) throw new RuntimeException($name); }
$a = '2026-09-13 18:00:00';
$b = '2026-09-13 18:00:30';
$text = "$a PB_DIAG_SESSION mode=2 interval_ms=30000\n$a PB_DIAG_STATE bots_online=6000 bots_target=6000\n$a PB_DIAG_ENGINE samples=100\n$a PB_DIAG_MANAGER pending_logins=0\n$a PB_DIAG_CACHE event_entries=123\n$a PB_DIAG_FAILURE rank=1 count=4 action=\"spell with spaces\" source=\"trigger\"\n$a PB_DIAG_POP {\"states\":{\"1\":4000,\"4\":2000}}\n";
$r = pb_parse($text);
check($r['latest']['state']['bots_online'] === 6000, 'count');
check($r['latest']['failures'][0]['action'] === 'spell with spaces', 'quoted action');
check($r['population']['data']['states'][1] === 4000, 'population');
$r = pb_parse($text . "$b PB_DIAG_STATE bots_online=20\n$b PB_DIAG_ENGINE samples=1\n");
check($r['latest']['state']['bots_online'] === 6000, 'partial batch must not replace complete sample');
$r = pb_parse($text . "$b PB_DIAG_SESSION mode=2\n");
check($r['latest'] === null && $r['population'] === null && count($r['history']) === 0, 'restart clears old session');
check(pb_parse('')['latest'] === null, 'missing log');
$r = pb_combat("$a PB_COMBAT_WINDOW sample_rate=16\n$a PB_COMBAT_COUNT count=12 reason=\"SPELL_FAILED_LINE_OF_SIGHT\"\n$b PB_COMBAT_WINDOW sample_rate=16\n$b PB_COMBAT_COUNT count=2 action=\"attack\"\n", $b);
check(count($r['counts']) === 1 && $r['counts'][0]['count'] === 2, 'combat window isolation');
$tmp = tempnam(sys_get_temp_dir(), 'pbdiag');
file_put_contents($tmp, "truncated prefix\ncomplete record\npartial");
check(pb_tail($tmp, 29) === "complete record\n", 'tail boundaries');
unlink($tmp);
echo "PASS: completed windows, restart isolation, quoted fields, population, combat sampling, missing logs and bounded tail.\n";
