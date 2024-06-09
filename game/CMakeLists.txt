cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

enable_language(C)
project(SpaceShip VERSION 0.0.1 LANGUAGES C CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

set(SFML_STATIC_LIBRARIES TRUE)
include(FetchContent)

FetchContent_Declare(SFML SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../externals/sfml)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(Lua SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../externals/lua)
FetchContent_MakeAvailable(Lua)

FetchContent_Declare(Sol2 SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../externals/sol2)
FetchContent_MakeAvailable(Sol2)

set(sources_files ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Object.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Actor.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/InputEvent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/InputManager.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/InputListener.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameStateBase.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameStateManager.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameLoop.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameWindow.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/World.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/MissionGameState.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/ShellGameState.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameObject.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameObjectComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Renderer.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Vector2D.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/PositionComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Timer.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/MeshComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Character.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/ScaleComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/RotationComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/PlayerController.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/MoveComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/PhysicComponent.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Physic.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/QuadTree.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Objective.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/ISubSystem.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Configs.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/GameEngine.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/InputSubSystem.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/RenderSubSystem.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Level.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/LevelScriptBuilder.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/IScriptBuilder.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/ScriptSubSystem.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/ScriptManager.cpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/MissionGameStateScriptBuilder.cpp)
source_group("Source Files\\game" FILES ${sources_files})

set(headers_files ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/InputEvent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Object.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Actor.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/InputManager.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/InputListener.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameStateBase.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameStateManager.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameLoop.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameWindow.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/World.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/MissionGameState.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/ShellGameState.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameObject.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameObjectComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Renderer.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Vector2D.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/PositionComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Timer.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/MeshComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Character.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/ScaleComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/RotationComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/PlayerController.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/MoveComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/PhysicComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Physic.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/QuadTree.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Objective.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/ISubSystem.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Global.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Configs.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/GameEngine.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/InputSubSystem.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/RenderSubSystem.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/Level.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/LevelScriptBuilder.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/IScriptBuilder.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/ScriptSubSystem.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/ScriptManager.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ssg/MissionGameStateScriptBuilder.hpp)
source_group("Header Files\\game" FILES ${headers_files})

add_executable(${PROJECT_NAME} ${headers_files} ${sources_files})
target_link_libraries(${PROJECT_NAME} PUBLIC SFML::Window SFML::Graphics SFML::System Lua::Library sol2::sol2)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SFML_INCLUDE_DIR})
