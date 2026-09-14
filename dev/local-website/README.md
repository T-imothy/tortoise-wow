# Local Turtle bot diagnostics

ManTech adapter for the existing local website at
`C:\Users\root\Desktop\WorkFolder\website\htdocs`.
Run `python install-mantech-diagnostics.py` to install/update the Turtle panel.
It preserves other realms and the site's local database configuration.
Runtime credentials are never copied here.

The adapter reads bounded tails (2 MiB general diagnostics, 1 MiB combat),
publishes complete scalar groups, resets history at session markers, and rejects
partial file records. Up to 120 scalar samples are returned. All diagnostics
remain read-only; there are no game command or individual-bot queries.
Online state checks only the configured local Turtle world port 8088.
Log timestamps use the development PC's America/Chicago timezone.

The core's existing 30-second diagnostic scan emits PB_DIAG_POP aggregate counts
at the joined world maintenance boundary. No live Player pointer crosses threads
for this output. States are exclusive: dead, combat, moving, casting, idle/other.
These are physical snapshots, not proof of persistent inactivity or action success.
Engine/action counts and combat samples retain their distinct sampling semantics.
Missing/stale data remains visibly marked; this panel does not fabricate the old
Sagiroth roster, death totals, persistent issues or per-bot live map.

Zone labels come from the current Turtle AreaTable.dbc. Regenerate using
`python extract-turtle-zone-names.py` when the local client data changes.

Regression: `php test-mantech-diagnostics.php` covers complete/partial windows,
session resets, quoted fields, aggregate populations, isolated combat windows,
missing files and bounded-tail record edges. PHP 7.4 syntax and JavaScript syntax
were checked, and the local browser displayed live bot states/classes/races/zones,
world timing, failures, and combat observations after deployment.
