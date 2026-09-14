from pathlib import Path
import re

web = Path(r'C:\Users\root\Desktop\WorkFolder\website\htdocs')
work = Path(__file__).parent
for name in ('mantech-bot-diagnostics.php', 'mantech-bot-diagnostics.js', 'turtle-zone-names.json'):
    (web / name).write_bytes((work / name).read_bytes())
p = web / 'api.php'
s = p.read_text(encoding='utf-8')
a = s.index('function api_bot_diagnostics(): void')
b = s.index('\nfunction text_param(', a)
s = s[:a] + '''require_once __DIR__ . '/mantech-bot-diagnostics.php';
function api_bot_diagnostics(): void
{
    if (realm_config()['key'] !== 'turtle') {
        json_out(array('error' => 'Bot diagnostics is available only for Turtle'), 404);
    }
    json_out(mantech_bot_diagnostics());
}
''' + s[b:]
p.write_text(s, encoding='utf-8')
p = web / 'app.js'
s = p.read_text(encoding='utf-8')
if 'async function loadBotDiagnostics(){' in s:
    a = s.index('async function loadBotDiagnostics(){')
    b = s.index('function applyRealmUi()', a)
    s = s[:a] + s[b:]
s = s.replace('let selectedRealm=savedRealm();', "let selectedRealm=location.hash==='#bot-diagnostics'?'turtle':savedRealm();")
p.write_text(s, encoding='utf-8')
p = web / 'index.html'
s = p.read_text(encoding='utf-8')
a = s.index('<section id="bot-diagnostics"')
b = s.index('</section>', a) + len('</section>')
panels = ''.join(f'<div class="featurePanel"><h3>{title}</h3><div id="{id}"></div></div>' for title,id in [('Physical state','botStateBars'),('Classes','botClassBars'),('Levels','botLevelBars'),('Races','botRaceBars'),('Top zones','botZoneBars'),('AI execution & caches','botEngineMetrics')])
s = s[:a] + '''<section id="bot-diagnostics" class="turtleOnly">
<div class="sectionHead"><div><p class="eyebrow">MANTECH PLAYERBOTS · TURTLE DEV</p><h2>Bot diagnostics</h2></div><div id="botTelemetryChecked" class="dataMeta">Checking diagnostics…</div></div>
<div id="botTelemetryNotice" class="botTelemetryNotice" role="status" aria-live="polite">Loading ManTech telemetry…</div>
<div id="botLiveContent"><div id="botTelemetryCards" class="botTelemetryCards"></div>
<div id="botTrends" class="pbTrends featurePanel"></div>
<p class="resourceNote" id="botPopulationTime"></p>
<div class="pbGrid">''' + panels + '''</div>
<p class="resourceNote">Physical states are an instantaneous snapshot, with priority: dead, combat, moving, casting, then idle / other. Idle includes looting, waiting, resting and other stationary actions; it does not mean AI is disabled. The activity controller is shown separately above.</p>
<div class="featurePanel"><h3>Top action failures</h3><p class="resourceNote">Counts cover the latest diagnostic window. Failed or impossible actions can be normal decisions; correlate repeated failures with activity and combat traces.</p><div id="botFailureRows" class="tableWrap"></div></div>
<div class="featurePanel"><h3>Combat & strategy observations</h3><p id="botCombatTime" class="resourceNote"></p><p class="resourceNote">Sampled action and spell checks, including noncombat strategy decisions. Successful dispatch is not proof of a completed spell or damage dealt.</p><div id="botCombatRows" class="tableWrap"></div></div>
<details class="featurePanel"><summary>Recent sampled bot traces</summary><div id="botTraceRows" class="tableWrap"></div></details>
</div><p class="resourceNote">Read-only ManTech diagnostics, refreshed every 5 seconds from approximately 30-second server windows. Charts retain up to 120 samples available in the bounded log tail; stale data is labelled. No Sagiroth service or GM sign-in is required.</p>
</section>''' + s[b:]
s = re.sub(r'(<script src="/app.js)[^"]*', r'\1?v=20260913.mantech54', s)
s = re.sub(r'<script src="/mantech-bot-diagnostics.js[^\"]*"></script>', '', s)
s = s.replace('<script src="/app.js', '<script src="/mantech-bot-diagnostics.js?v=20260913.mantech54"></script><script src="/app.js')
s = re.sub(r'bot-diagnostics.css\?v=[^"]+', 'bot-diagnostics.css?v=20260913.mantech54', s)
p.write_text(s, encoding='utf-8')
p = web / 'bot-diagnostics.css'
p.write_text(p.read_text(encoding='utf-8').split('/* ManTech diagnostic panels */')[0], encoding='utf-8')
with p.open('a', encoding='utf-8') as f:
    f.write('''
/* ManTech diagnostic panels */
.pbGrid{display:grid;grid-template-columns:repeat(2,minmax(0,1fr));gap:16px}.pbGrid .featurePanel{margin:0}.pbTrends{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:24px}.pbTrend{min-width:0;color:var(--gold)}.pbTrend h4{color:var(--text);margin:0}.pbTrend h4 small{float:right;color:var(--muted)}.pbTrend svg{width:100%;height:120px}.pbTrendAxis{display:flex;justify-content:space-between;font-size:11px;color:var(--muted)}.pbBar{position:relative;display:flex;justify-content:space-between;gap:15px;margin:7px 0;padding:6px 8px;min-height:30px;font-size:13px}.pbBar i{position:absolute;left:0;top:0;bottom:0;background:var(--gold);opacity:.14;pointer-events:none}.pbBar span,.pbBar b{position:relative}.pbBar small{font-weight:normal;color:var(--muted);padding-left:8px}.pbStale{opacity:.55}#bot-diagnostics details summary{cursor:pointer;font-weight:600}#bot-diagnostics td{overflow-wrap:anywhere}#bot-diagnostics .tableWrap{max-height:520px;overflow:auto}#bot-diagnostics table{width:100%}@media(max-width:850px){.pbGrid,.pbTrends{grid-template-columns:1fr}.botTelemetryCards{grid-template-columns:repeat(2,minmax(0,1fr))}}@media(max-width:520px){.botTelemetryCards{grid-template-columns:1fr}}
''')
print('Installed ManTech diagnostics adapter and dashboard in the local website.')
