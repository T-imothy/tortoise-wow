-- Manual world-data cleanup for Turtle build90. No character data changes.
-- AreaTable maps 5180 -> 5179 and 2041 -> 406. The native loader skips
-- subzone links. Existing parent links already cover the same factions.
-- Remove only the two proven redundant rows, retaining all parent policies.
DELETE child FROM game_graveyard_zone AS child
JOIN game_graveyard_zone AS parent ON parent.id=child.id
 AND (parent.faction=0 OR parent.faction=child.faction)
WHERE (child.id=136 AND child.ghost_zone=5180 AND child.faction=0 AND parent.ghost_zone=5179)
 OR (child.id=137 AND child.ghost_zone=2041 AND child.faction=67 AND parent.ghost_zone=406);
