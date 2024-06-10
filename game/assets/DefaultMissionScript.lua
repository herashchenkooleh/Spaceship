mission = MissionGameState.new()

mission.level = "DefenceMissionLevel.lua"
mission.number_objectives = 3
mission.player_controller = "PlayerContoller.lua"

objective1 = Objective.new()
objective1.name = "MissionObjective1"

function objective1:Update (self)
    print("Hello from objective1")
end

mission.objectives = {
    objective1,
    Objective.new(),
    Objective.new()
}