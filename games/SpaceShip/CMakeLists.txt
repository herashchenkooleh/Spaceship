cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(SpaceShip VERSION 0.0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin)

set(SFML_STATIC_LIBRARIES TRUE)

include(ExternalProject)

ExternalProject_Add(lua
   URL "https://www.lua.org/ftp/lua-5.4.6.tar.gz"
   CONFIGURE_COMMAND ""
   BUILD_COMMAND make macosx
   BUILD_ALWAYS YES
   BUILD_IN_SOURCE YES
   INSTALL_COMMAND ""
)
ExternalProject_get_property(lua SOURCE_DIR)
set(LUA_INCLUDE_DIR ${SOURCE_DIR}/src)
add_library(liblua STATIC IMPORTED)
add_dependencies(liblua lua)
if (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows")
    set(LUA_LIBRARY liblua.lib)
else()
    set(LUA_LIBRARY liblua.a)
endif()
set_target_properties(liblua PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/lua-prefix/src/lua/src/${LUA_LIBRARY})

include(FetchContent)
FetchContent_Declare(SFML SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../engine)
FetchContent_MakeAvailable(SFML)

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
                  ${CMAKE_CURRENT_SOURCE_DIR}/sources/QuadTree.cpp)
source_group("Source Files\\game" FILES ${sources_files})

set(headers_files ${CMAKE_CURRENT_SOURCE_DIR}/include/InputEvent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Object.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Actor.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/InputManager.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/InputListener.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/GameStateBase.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/GameStateManager.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/GameLoop.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/GameWindow.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/World.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/MissionGameState.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ShellGameState.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/GameObject.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/GameObjectComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Renderer.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Vector2D.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/PositionComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Timer.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/MeshComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Character.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/ScaleComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/RotationComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/PlayerController.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/MoveComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/PhysicComponent.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/Physic.hpp
                  ${CMAKE_CURRENT_SOURCE_DIR}/include/QuadTree.hpp)
source_group("Header Files\\game" FILES ${headers_files})

add_executable(${PROJECT_NAME} ${headers_files} ${sources_files})
target_link_libraries(${PROJECT_NAME} PUBLIC SFML::Window SFML::Graphics SFML::System liblua)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SFML_INCLUDE_DIR} ${LUA_INCLUDE_DIR})
