cmake_minimum_required(VERSION 3.22.1)

set (CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)

set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/g++.exe" )
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/gcc.exe" )

project(GPGPU)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.c)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)


target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
    OpenGL::GL
    glfw
    glm::glm
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)