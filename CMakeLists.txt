cmake_minimum_required(VERSION 3.23)
project(ClientServerChatroom)
set(CMAKE_CXX_STANDARD 20)

link_directories("/usr/local/Cellar/llvm/15.0.0/lib/c++")

add_subdirectory(myNetworking)
add_subdirectory(myClient)
add_subdirectory(myServer)