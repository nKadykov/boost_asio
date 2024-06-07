cmake_minimum_required(VERSION 3.10)
project(boost_asio_project)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(boost_asio_project src/tcp_server.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(boost_asio_project PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(boost_asio_project PRIVATE Boost::system)