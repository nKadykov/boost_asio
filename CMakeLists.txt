cmake_minimum_required(VERSION 3.10)
project(timer_async_example)

set(CMAKE_CXX_STANDART 23)
set(CMAKE_CXX_STANDART_REQUIRED True)

set(CMAKE_TOOLCHANE_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

include_directories(include) 

add_executable(timer_async_example src/timer_async_example.cpp)

find_package(Boost REQUIRED COMPONENTS system)
target_include_directories(timer_async_example PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(timer_async_example PRIVATE Boost::system)