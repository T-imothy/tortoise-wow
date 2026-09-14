# Penqle upstream integration — September 14, 2026

Merged upstream main d886113c21ffb80c779b600c0d87b799532fe945 into the
ManTech Turtle development branch. The upstream merge is a7381ab1; native
compatibility corrections and focused tests are maintained separately.

Incoming changes: delivery-gated chat callbacks, a permitted yell callback,
server-side trade initiation, and upstream documentation. No database migration
or runtime configuration change is required by this update.

Compatibility corrections:
- Trade initiation retains fingerprint bans, hardcore restrictions and optional
  Eluna approval, and rejects absent sessions/maps before touching trade state.
- Addon payloads cannot be parsed as native text commands on any group chat
  path. Ordinary chat handling and destination checks remain in force.

Validation before deployment:
- Native helper: 24 source-extracted cases with Eluna enabled, 24 disabled.
- Chat preprocessing: 56 source-extracted validity/language/type/message cases.
- Existing bot-chat admission: 46,080 policy cases and 10,000-recipient checks.
- Existing chat-link parsing: malformed/overflow/equivalence and concurrent readers.

The helpers use controlled dependencies; this is not a complete in-game Eluna
or item/gold settlement test. Active ManTech bots continue to use the native
trade opcode path; the new helper remains additive with no module consumer.

Build and live acceptance:
- Release build with development diagnostics passed. The final incremental build
  includes the addon correction and compatibility commit 28968503.
- Deployed world binary SHA256: `D99454D376953766FBF6191151C0CE2C6DD96DE3B2F0A29BDDBD407347DCA147`.
- Dev world PID 36008; existing login server PID 30692.
- Native authentication/entry, invite (0.578s), cross-map summon
  (0.609s), whisper summon, master/FFA/group loot and group retention passed.
- Say, yell, party and temporary-channel delivery passed. A party addon payload
  containing `.bot remove` did not execute the command or remove the owned bot.
- Native bot trade opened/cancelled with the bot stationary. The first attempt
  was cancelled before opening; no trace was added to attribute that cancellation.
  This is not proof of correct trading while moving. No item/gold exchange was tested.
- Native logout and fixture position restoration passed.
- Latest bounded sample 2026-09-14 12:24:37: 3936 bots, 113ms average,
  0 world actions pending, 0 rejected. No new crash dump
  or SQL/assertion/fatal markers in the current world startup log.
- Existing configs verified byte-for-byte unchanged. Target remains
  10000 bots, botActiveAlone=100,
  DisableActivityPriorities=1. Population is still growing;
  this update has not completed a full-population or multi-hour soak.
- Existing local diagnostics website restarted at http://127.0.0.1:8080/.
  Production was not deployed or restarted.

Receipt: local workspace `work/turtle-build89-validation-receipt.json`.
Full live fixture checks: `work/test-build89-live.py`; private fixture credentials
remain outside the source repository. Source tests are retained in tests/architecture.
