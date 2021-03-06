cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

# B2D - Box2D phyics library
add_subdirectory("lib/b2d/Box2D")
#include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

## Tile loader lib
file(GLOB_RECURSE SOURCE_FILES lib_tile_level_loader/*.cpp lib_tile_level_loader/*.h)
add_library(lib_tile_level_loader STATIC ${SOURCE_FILES})
target_include_directories(lib_tile_level_loader INTERFACE "${CMAKE_SOURCE_DIR}/lib_tile_level_loader/" )
target_link_libraries(lib_tile_level_loader sfml-graphics lib_maths)

# Maths lib
add_library(lib_maths INTERFACE)
target_sources(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths/maths.h")
target_include_directories(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths" SYSTEM INTERFACE ${SFML_INCS})

#### Practical 1 ####
file(GLOB_RECURSE SOURCES practical_1/*.cpp practical_1/*.h)
add_executable(PRACTICAL_1 ${SOURCES})
target_include_directories(PRACTICAL_1 PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_1 sfml-graphics)

#### Pong ####
file(GLOB_RECURSE SOURCES pong/*.cpp pong/*.h)
add_executable(PONG ${SOURCES})
target_include_directories(PONG PRIVATE ${SFML_INCS})
target_link_libraries(PONG sfml-graphics)

#### Space Invaders ####
file(GLOB_RECURSE SOURCES space_invaders/*.cpp space_invaders/*.h)
add_executable(SPACE_INVADERS ${SOURCES})
target_include_directories(SPACE_INVADERS PRIVATE ${SFML_INCS})
target_link_libraries(SPACE_INVADERS sfml-graphics)

#### Set resource folder in build folder ####
set_target_properties(SPACE_INVADERS 
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)

add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/res"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res
)

add_custom_target(copy_assets ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/assets"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/assets
)

#### Tile Engine ####
file(GLOB_RECURSE SOURCES tile_engine/*.cpp tile_engine/*.h)
add_executable(TILE_ENGINE ${SOURCES})
target_include_directories(TILE_ENGINE PRIVATE ${SFML_INCS})
target_link_libraries(TILE_ENGINE sfml-graphics lib_tile_level_loader)
add_dependencies(TILE_ENGINE copy_resources)

set_target_properties(TILE_ENGINE
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)

#### PAC MAN ####
file(GLOB_RECURSE SOURCES pac_man/*.cpp pac_man/*.h)
add_executable(PAC_MAN ${SOURCES})
target_include_directories(PAC_MAN PRIVATE ${SFML_INCS})
target_link_libraries(PAC_MAN sfml-graphics lib_tile_level_loader lib_ecm)
add_dependencies(PAC_MAN copy_resources)

set_target_properties(PAC_MAN
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)

file(GLOB_RECURSE SOURCE_FILES lib_ecm/*.cpp lib_ecm/*.h)
add_library(lib_ecm STATIC ${SOURCE_FILES})
target_include_directories(lib_ecm INTERFACE "${CMAKE_SOURCE_DIR}/lib_ecm" )
target_link_libraries(lib_ecm PRIVATE lib_maths)

#### PHYSICS ####
file(GLOB_RECURSE SOURCES physics/*.cpp physics/*.h)
add_executable(PHYSICS ${SOURCES})
target_include_directories(PHYSICS SYSTEM PRIVATE ${SFML_INCS} ${B2D_INCS})
target_link_libraries(PHYSICS Box2D sfml-graphics)
set(EXECUTABLES ${EXECUTABLES} PRACTICAL_PHYSICS)

set_target_properties(PHYSICS
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)