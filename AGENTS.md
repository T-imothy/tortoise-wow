# Core-preservation requirements

User-directed engineering policy for this Turtle fork:

- Preserve the core's native systems, generic behaviors, and custom-content semantics. A symptom disappearing is not sufficient evidence that a fix is correct.
- Before changing a subsystem, trace its actual execution path, callers, data contracts, ownership/threading, and supported variants. Inspect relevant native implementations and working examples; do not assume complete knowledge of the core.
- Prefer correcting configuration/data or the responsible native implementation as appropriate to the demonstrated cause. Reuse existing APIs and lifecycle hooks rather than introducing parallel mechanisms, bypasses, hardcoded special cases, or duplicated behavior.
- Apply this to all systems, including boss/creature AI, combat, spells, trainers, quests, loot, instance events/doors, movement/transports, playerbots, persistence, and scheduling. Preserve script hooks, prerequisites, side effects, state transitions, and custom Turtle behavior.
- Use our CMaNGOS Classic/TBC/WotLK and relevant upstream implementations as references, but verify compatibility with Turtle's contracts before porting. Similar names do not establish equivalent behavior or threading guarantees.
- Add new mechanisms or workarounds only when investigation demonstrates that existing facilities cannot meet the requirement. Explain the gap, alternatives considered, and compatibility risks before a materially different design is implemented; obtain user direction where it expands scope.
- Validate affected variants and failure paths, not only the original reproduction. Include related consumers, repeated requests, persistence, and concurrency where applicable. Report exactly what was tested and what remains unverified; compilation alone is not gameplay validation.
- Track temporary diagnostics and their overhead/removal controls. Do not use diagnostics or fallback paths to silently conceal an unresolved failure.

These requirements do not authorize unrelated rewrites, deployment, production database changes, or server start/stop operations.

## Durable core reference

Before investigating or editing a subsystem, consult `docs/CORE_SYSTEMS_GUIDE.md` and the relevant findings in `docs/CORE_COMPATIBILITY_AUDIT_2026-09-05.md`, then reopen the current source and callers. These documents describe a dated baseline, not permanent proof of correctness.

- `docs/core-audit/COVERAGE.md` inventories every database dungeon/raid map and all dungeon source directories; the JSON matrices hold per-template/binding evidence.
- Regenerate source indexes with `tools/audit-core-contracts.ps1` after relevant changes. DB refresh is explicit and read-only; never infer production write/deploy authority from an audit.
- Distinguish C++ script selection, EventAI events, native spell lists, dynamic summons and area-trigger routes. Missing filenames, empty event lists, rank flags and blank instance bindings are not sufficient to declare content broken.
- Update the guide and focused regression coverage when changing a native contract. Track diagnostic additions/removal in `doc/TURTLE_DIAGNOSTICS.md`.

## Local development location (user-directed relocation, 2026-09-12)

Use this checkout as the active source. Read LOCAL_DEVELOPMENT.md for build/test
commands and the user-selected output directory/shared MySQL instance. Earlier
Codex sandbox checkouts and isolated databases are obsolete. Runtime configuration
contains local database credentials and must stay outside the Git repositories.
