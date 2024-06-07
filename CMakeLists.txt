cmake_minimum_required(VERSION 3.10)
project(messenger_client)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

add_executable(messenger_client src/messenger_client.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(messenger_client PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(messenger_client PRIVATE Boost::system)