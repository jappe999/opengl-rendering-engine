cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake)

project(Game VERSION 0.1.0)

include_directories(src)

file(GLOB_RECURSE DEMO_SRC CONFIGURE_DEPENDS demo/*.cpp demo/*.c demo/*.hpp demo/*.h)
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS src/*.cpp src/*.c src/*.hpp src/*.h)

add_library(ore STATIC ${ENGINE_SRC})
add_executable(main ${DEMO_SRC})

target_link_libraries(main PRIVATE ore)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)
target_link_libraries(ore PRIVATE glfw)

find_package(yaml-cpp CONFIG REQUIRED)
target_link_libraries(ore PRIVATE yaml-cpp)

file(COPY demo/assets DESTINATION .)