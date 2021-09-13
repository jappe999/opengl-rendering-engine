cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake)

project(Game VERSION 0.1.0)

include_directories(src)
include_directories(libs)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.c src/*.hpp src/*.h)

add_executable(main ${SOURCES})

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

file(COPY assets DESTINATION .)