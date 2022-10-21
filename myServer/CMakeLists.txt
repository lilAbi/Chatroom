cmake_minimum_required(VERSION 3.23)
project(server)

set(CMAKE_CXX_STANDARD 20)


add_executable(server main.cpp)

target_include_directories(server PUBLIC myNetworking)
target_link_libraries(server PUBLIC myNetworking)