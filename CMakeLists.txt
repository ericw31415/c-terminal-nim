cmake_minimum_required(VERSION 3.19)
project(c-terminal-nim)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
message("Building from ${CMAKE_SOURCE_DIR}")
message("Building into ${CMAKE_BINARY_DIR}")

add_subdirectory(src)

target_compile_options(nim PUBLIC -O2 -Wall -Wextra -Wshadow)
target_link_libraries(nim -s)
