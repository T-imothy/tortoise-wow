-- Playerbot event updates used to DELETE then INSERT while mass bot
-- activation held a transaction. Concurrent login/update callbacks could
-- lock the same secondary-index ranges in opposite order and deadlock.
-- Keep one canonical row per event and make INSERT ... ON DUPLICATE KEY UPDATE
-- a single atomic point operation.
DELETE older
FROM `ai_playerbot_random_bots` older
JOIN `ai_playerbot_random_bots` newer
  ON newer.`owner` = older.`owner`
 AND newer.`bot` = older.`bot`
 AND newer.`event` <=> older.`event`
 AND newer.`id` > older.`id`;

ALTER TABLE `ai_playerbot_random_bots`
  DROP INDEX `idx_owner_bot_event`;

ALTER TABLE `ai_playerbot_random_bots`
  ADD UNIQUE INDEX `uq_owner_bot_event` (`owner`, `bot`, `event`);
