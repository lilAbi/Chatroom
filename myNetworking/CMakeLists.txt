cmake_minimum_required(VERSION 3.23)
project(myNetworking)
set(CMAKE_CXX_STANDARD 20)


find_package(Boost REQUIRED)
include_directories(Boost_INCLUDE_DIRS)
link_directories(${Boost_LIBRARY_DIR})

file(GLOB SOURCES CONFIGURE_DEPENDS src/* src/*/*)

add_library(myNetworking ${SOURCES})

target_include_directories(myNetworking
        PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            ${Boost_INCLUDE_DIRS}
        )

target_link_libraries(myNetworking ${Boost_LIBRARIES})