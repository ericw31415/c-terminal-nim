cmake_minimum_required(VERSION 3.19)

set(CMAKE_C_FLAGS "-Wall -Wextra -Wshadow" CACHE STRING
    "Flags used by the C compiler during all build types")
set(CMAKE_C_FLAGS_RELEASE "-O2" CACHE STRING
    "Flags used by the C compiler during RELEASE builds.")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "-s" CACHE STRING
    "Flags used by the linker during RELEASE builds.")

project(c-terminal-nim C)

if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING
        "List of configuration types to build" FORCE)
    unset(CMAKE_C_FLAGS_MINSIZEREL CACHE)
    unset(CMAKE_C_FLAGS_RELWITHDEBINFO CACHE)
    unset(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL CACHE)
    unset(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO CACHE)

    string(REPLACE ";" ", " configs "${CMAKE_CONFIGURATION_TYPES}")
    message(STATUS "Found configurations: ${configs}")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
message(STATUS "Building from ${CMAKE_SOURCE_DIR}")
message(STATUS "Generating buildsystem in ${CMAKE_BINARY_DIR}")

add_subdirectory(src)
