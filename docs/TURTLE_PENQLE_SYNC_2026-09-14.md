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

Build and live acceptance: pending in this working record.
