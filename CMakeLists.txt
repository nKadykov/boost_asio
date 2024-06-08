cmake_minimum_required(VERSION 3.10)
project(coroutine)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include) 

add_executable(coroutine src/coroutine.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(coroutine PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(coroutine PRIVATE Boost::system)