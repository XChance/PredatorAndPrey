cmake_minimum_required(VERSION 3.12)
project(Predator_and_Prey)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES "Source Files/main.cpp" "Source Files/Application.cpp" "Source Files/Automaton.cpp" "Header Files/Automaton.h" "Header Files/Creature.h" "Source Files/Creature.cpp" "Source Files/Random.cpp" "Header Files/Random.h")

add_executable(Predator_and_Prey ${SOURCE_FILES})
 
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Predator_and_Prey ${SFML_LIBRARIES})
endif()