# Turtle console review - September 22

Reviewed the running production process 1156 and server_2026-09-21_21-48-34.log.
No production files, database records, config or processes were changed. No build,
deployment or Git publication was performed.

## Local fixes ready for review

* Native bot automatic shopping now includes GetVendorTemplateItems(). The Classic
  preprocessor guard incorrectly excluded inventories that Turtle supports.
  Production examples include Karlos Fieldings and Vivi McGoldings.
* Explicit shopping now tracks success separately for each requested item. Buying
  an earlier item no longer prevents a later item from using the template inventory
  or reporting that it could not be bought.
* sql/custom/world/20260922_cursed_mage_death_target.sql corrects script 852401.
  It selects the killer supplied by CreatureEventAI::JustDied/ProcessAction rather
  than looking for the dead creature's current victim. The review counted 79
  failures of this script after startup. Spell and cast flags remain unchanged.
  This SQL is manual and has NOT been applied; rebuilding alone does not apply it.

Source diff and whitespace checks passed. Native vendor purchase and death-event
call paths were inspected. No compilation or gameplay validation was performed.

## Remaining findings, not silently suppressed

* Warden Thelwater (1719, GUID89325, map0 instance5) reached 100 active summons.
  Script171902 then fails to summon5043. The database contains duplicate wave rows
  and duplicate generic lane scripts. Its despawn type6 only starts the 15-second
  timer AFTER death, so it does not bound surviving prisoners. Review the lane
  paths, end-of-route cleanup and database migration provenance before choosing
  the content fix. Raising the summon limit is not a correction.
* Empty vendors1650 (60 messages),91292 (13),60556 and60576 have no direct inventory
  and vendor_id0 in production. The shared-inventory code fix does not repair
  those records. Establish the intended services before removing flags or adding
  inventory. Fahrad6707 also reports an empty trainer list.
* Shadowforge Chanter274203 selects a non-primary threat target: it can legitimately
  find none against one opponent (18 messages). Do not retarget Sleep onto the tank
  merely to remove a log line. Script6293002 similarly failed friendly-injured
  target selection17 times; check its event conditions before changing behavior.
* Spell24934 is missing a gameobject script target (5 messages). Missing waypoint
  paths include GUID10740/entry1400. These require content-specific data fixes.
* Creature91814 produced zero-velocity spline failures. Trace movement state and
  template speeds before altering movement validation.
* Malformed client packets from10.0.0.77 are separate from server-side bot AI.
  Five have the same size18245/opcode539959380; identify the connecting client/tool.
* Startup has additional equipment, pet spell-list, trainer, script and movement
  data warnings. Runtime counts above exclude startup before21:50 server time.

## Runtime health

All6000 bots remained online. At13:31 UTC, resident memory was10.14GiB and private
memory10.42GiB. The new database_query_results counter was0. This supports the
query ownership repair; it is not proof that all memory growth is fixed.
Recent world averages were roughly146-155ms, with a7188ms spike at06:22:46 server
time. That spike needs separate attribution; no causal link to these content
errors was established. No expensive heap capture was triggered during this review.

## User workflow

Run Build-Local-Turtle.cmd, then deploy/restart/test as usual for the bot code.
Apply the supplied SQL separately to the Turtle world database when ready.
Verify Cursed Mage's death spell reaches its killer and shopping works with both
direct and template inventories, including multiple requested items.
Publish only after testing, using the existing baseline workflow.

## Teleport acknowledgment follow-up

The initial review omitted info.log: it contained 1,638 current-run
MSG_MOVE_TELEPORT_ACK warnings. Sample acknowledgments had counter N and the
next movement counter N+1; that difference is normal because sending increments
the counter. The fault is the absent pending record, not that increment.

Confirmed source defect: SwitchInstance asks ResolvePendingMovementChanges to
exclude teleports, but the old loop unconditionally popped every record. Near
teleport state could remain set while its ACK record disappeared. The local core
fix retains excluded teleport entries and still resolves the other movement
changes. Completion consumes a copied record before callbacks, avoiding an
iterator/reference surviving native relocation. No ACK validation was weakened.

This is a proven record-loss path consistent with the warnings, not a runtime
trace establishing that every one of the 1,638 warnings took that path. Build
and deploy the core change, then check a fresh info.log for recurrence. No build,
restart, deployment or additional production changes were made in this follow-up.
