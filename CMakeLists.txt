cmake_minimum_required(VERSION 3.26)
project(Lab14 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab14 main.c
        libs/data_structures/vector/int_vector.h
        libs/data_structures/vector/int_vector.c)

add_subdirectory(libs)
target_link_libraries(Lab14 data_structures)
target_compile_definitions(Lab14 PRIVATE -DNDEBUG)
