cmake_minimum_required(VERSION 3.10)
project(tcp_server)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(tcp_server src/tcp_server.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(tcp_server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(tcp_server PRIVATE Boost::system)