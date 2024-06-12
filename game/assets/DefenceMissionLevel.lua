window_size = GetWindowSize()

background = SpawnPawnObject("background.png", Transform.new(window_size, 0.0, Vector2D.new(0.0, 0.0)))
foreground = SpawnPawnObject("foreground.png", Transform.new(window_size, 0.0, Vector2D.new(0.0, 0.0)))

relative_defence_area_1_pos = Vector2D.new(0.3, 0.3)
relative_defence_area_2_pos = Vector2D.new(0.7, 0.3)
relative_defence_area_3_pos = Vector2D.new(0.5, 0.7)

min_window_dim = math.min(window_size.X, window_size.Y)
relative_defence_area_1_size = Vector2D.new(500.0 / min_window_dim)
relative_defence_area_2_size = Vector2D.new(500.0 / min_window_dim)
relative_defence_area_3_size = Vector2D.new(500.0 / min_window_dim)

relative_planet_1_size = Vector2D.new(250.0 / min_window_dim)
relative_planet_2_size = Vector2D.new(250.0 / min_window_dim)
relative_planet_3_size = Vector2D.new(300.0 / min_window_dim, 250.0 / min_window_dim)

min_window_size = Vector2D.new(min_window_dim, min_window_dim)

defence_area_1 = SpawnPawnObject("defence_area.png", Transform.new(relative_defence_area_1_size * min_window_size, 0.0, relative_defence_area_1_pos * window_size, Vector2D.new(0.5, 0.5)))
defence_area_2 = SpawnPawnObject("defence_area.png", Transform.new(relative_defence_area_2_size * min_window_size, 0.0, relative_defence_area_2_pos * window_size, Vector2D.new(0.5, 0.5)))
defence_area_3 = SpawnPawnObject("defence_area.png", Transform.new(relative_defence_area_3_size * min_window_size, 0.0, relative_defence_area_3_pos * window_size, Vector2D.new(0.5, 0.5)))

defence_area_1.visible = false
defence_area_2.visible = false
defence_area_3.visible = false

planet_1 = SpawnPawnObject("planet1.png", Transform.new(relative_planet_1_size * min_window_size, 0.0, relative_defence_area_1_pos * window_size, Vector2D.new(0.5, 0.5)))
planet_2 = SpawnPawnObject("planet2.png", Transform.new(relative_planet_2_size * min_window_size, 0.0, relative_defence_area_2_pos * window_size, Vector2D.new(0.5, 0.5)))
planet_3 = SpawnPawnObject("planet3.png", Transform.new(relative_planet_3_size * min_window_size, 0.0, relative_defence_area_3_pos * window_size, Vector2D.new(0.5, 0.5)))

character = SpawnCharacter("ship.png", Transform.new(Vector2D.new(65.0, 65.0), 0.0, Vector2D.new(300.0, 300.0), Vector2D.new(0.5, 0.5)), "bullet.png", 100.0)

defence_area_1.Update = function (self)
    dist_vec = character.transform.position - defence_area_1.transform.position
    distance = Length(dist_vec)
    print(distance, (defence_area_1.transform.size.X / 2.0))
    if distance < (defence_area_1.transform.size.X / 2.0) then
        defence_area_1.visible = true
    else
        defence_area_1.visible = false
    end
end

defence_area_2.Update = function (self)
    dist_vec = character.transform.position - defence_area_2.transform.position
    distance = Length(dist_vec)
    print(distance, (defence_area_2.transform.size.X / 2.0))
    if distance < (defence_area_2.transform.size.X / 2.0) then
        defence_area_2.visible = true
    else
        defence_area_2.visible = false
    end
end

defence_area_3.Update = function (self)
    dist_vec = character.transform.position - defence_area_3.transform.position
    distance = Length(dist_vec)
    print(distance, (defence_area_3.transform.size.X / 2.0))
    if distance < (defence_area_3.transform.size.X / 2.0) then
        defence_area_3.visible = true
    else
        defence_area_3.visible = false
    end
end

-- level.game_objects = {}

-- level.game_objects[1] = DefenceAre.new()
-- level.game_objects[1].objective = "MissionObjective_1"
-- level.game_objects[1].shape = "circle"
-- level.game_objects[1].position = { 100.0 , 100.0 }
-- level.game_objects[1].size = { 100.0, 100.0 }

-- level.game_objects[2] = DefenceAre.new()
-- level.game_objects[2].objective = "MissionObjective_2"
-- level.game_objects[2].shape = "circle"
-- level.game_objects[2].position = { 300.0 , 300.0 }
-- level.game_objects[2].size = { 100.0, 100.0 }

-- level.game_objects[3] = DefenceAre.new()
-- level.game_objects[3].objective = "MissionObjective_3"
-- level.game_objects[3].shape = "circle"
-- level.game_objects[3].position = { 500.0 , 500.0 }
-- level.game_objects[3].size = { 100.0, 100.0 }