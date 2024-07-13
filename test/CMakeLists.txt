cmake_minimum_required(VERSION 3.22.1)
project(Testbed)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(testbed ${SOURCES})

target_link_libraries(testbed PUBLIC GPGPU)

set_target_properties(testbed
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})