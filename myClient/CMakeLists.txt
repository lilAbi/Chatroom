cmake_minimum_required(VERSION 3.23)
project(client)

set(CMAKE_CXX_STANDARD 20)


add_executable(client main.cpp)

target_include_directories(client PUBLIC myNetworking)
target_link_libraries(client PUBLIC myNetworking)