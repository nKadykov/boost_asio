cmake_minimum_required(VERSION 3.10)
project(game_client)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include) 

add_executable(game_client include/game_client.h src/game_client.cpp src/client.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(game_client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(game_client PRIVATE Boost::system)