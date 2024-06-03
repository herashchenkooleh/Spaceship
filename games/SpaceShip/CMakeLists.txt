cmake_minimum_required(VERSION 3.24 FATAL_ERROR)

project(SpaceShip VERSION 0.0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin)

set(SFML_STATIC_LIBRARIES TRUE)
list(APPEND CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/../../bin/lib/cmake")
find_package(SFML 3 COMPONENTS Window Graphics System)

set(sources_files ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp)
source_group("Source Files\\game" FILES ${sources_files})

set(headers_files ${CMAKE_CURRENT_SOURCE_DIR}/include/)
source_group("Header Files\\game" FILES ${headers_files})

add_executable(${PROJECT_NAME} ${headers_files} ${sources_files})

target_link_libraries(${PROJECT_NAME} PUBLIC SFML::Window SFML::Graphics SFML::System)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${SFML_INCLUDE_DIR})
