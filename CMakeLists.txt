cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_OSX_ARCHITECTURES "arm64")
set(CMAKE_CXX_STANDARD 17)

project(Game VERSION 0.1.0)

include_directories(src)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp src/*.c src/*.hpp src/*.h)

add_executable(main ${SOURCES})

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(yaml-cpp CONFIG REQUIRED)
target_link_libraries(main PRIVATE yaml-cpp)

file(COPY assets DESTINATION .)