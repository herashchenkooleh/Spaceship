state = MissionGameState.new()

state.level = "DefenceMissionLevel.lua"
state.number_objectives = 3
state.player_controller = "PlayerContoller.lua"
state.objectives = {}

state.objectives[1] = "MissionObjective_1.lua"
state.objectives[2] = "MissionObjective_2.lua"
state.objectives[3] = "MissionObjective_3.lua"