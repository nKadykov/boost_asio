cmake_minimum_required(VERSION 3.10)
project(game_server)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include) 

add_executable(game_server include/game_session.h src/game_session.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(game_server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(game_server PRIVATE Boost::system)