level = Level.new()

level.background = "MissionBackground.png"

level.character_mesh = "ship.png"

level.number_game_objects = 3

level.game_objects = {}

level.game_objects[1] = DefenceAre.new()
level.game_objects[1].objective = "MissionObjective_1"
level.game_objects[1].shape = "circle"
level.game_objects[1].position = { 100.0 , 100.0 }
level.game_objects[1].size = { 100.0, 100.0 }

level.game_objects[2] = DefenceAre.new()
level.game_objects[2].objective = "MissionObjective_2"
level.game_objects[2].shape = "circle"
level.game_objects[2].position = { 300.0 , 300.0 }
level.game_objects[2].size = { 100.0, 100.0 }

level.game_objects[3] = DefenceAre.new()
level.game_objects[3].objective = "MissionObjective_3"
level.game_objects[3].shape = "circle"
level.game_objects[3].position = { 500.0 , 500.0 }
level.game_objects[3].size = { 100.0, 100.0 }