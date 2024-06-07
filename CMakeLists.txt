cmake_minimum_required(VERSION 3.10)
project(messenger_server)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(messenger_server src/messenger_server.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(messenger_server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(messenger_server PRIVATE Boost::system)