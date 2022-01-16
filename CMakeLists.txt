cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake)
set(CMAKE_OSX_ARCHITECTURES "arm64")
set(CMAKE_CXX_STANDARD 17)

project(Game VERSION 0.1.0)

include_directories(ore)

file(GLOB_RECURSE DEMO_SRC CONFIGURE_DEPENDS demo/*.cpp demo/*.c demo/*.hpp demo/*.h)
file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS ore/*.cpp ore/*.c ore/*.hpp ore/*.h)
file(GLOB_RECURSE EDITOR_SRC CONFIGURE_DEPENDS rock/*.cpp rock/*.c rock/*.hpp rock/*.h)

add_library(ore STATIC ${ENGINE_SRC})

add_executable(demo ${DEMO_SRC})
add_executable(rock ${EDITOR_SRC})

target_link_libraries(demo PRIVATE ore)
target_link_libraries(rock PRIVATE ore)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(demo PRIVATE glfw)
target_link_libraries(rock PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(ore PRIVATE imgui::imgui)

find_package(yaml-cpp CONFIG REQUIRED)
target_link_libraries(ore PRIVATE yaml-cpp)
target_link_libraries(demo PRIVATE yaml-cpp)
target_link_libraries(rock PRIVATE yaml-cpp)

file(COPY demo/assets DESTINATION .)
file(COPY rock/assets DESTINATION .)