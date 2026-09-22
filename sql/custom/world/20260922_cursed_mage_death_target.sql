-- Apply manually to the Turtle world database. Not applied by this review.
-- JustDied supplies the killer as the provided target. A dead creature no
-- longer has a current combat victim, so TARGET_T_HOSTILE loses that target.
-- Keep the spell, triggered-cast flags and event timing unchanged.
UPDATE creature_ai_scripts
SET target_type = 0
WHERE id = 852401 AND command = 15 AND datalong = 16567
  AND datalong2 = 7 AND target_type = 1
  AND target_param1 = 0 AND target_param2 = 0 AND data_flags = 0;
