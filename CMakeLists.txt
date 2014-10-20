cmake_minimum_required(VERSION 2.8)

project(Life-After-Earth-III CXX)

include(CPackConfig.cmake)
include(GNUInstallDirs)

#find_package(Boost REQUIRED COMPONENTS filesystem system)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1 sfml-audio>=2.1)

add_definitions(-Wall -g -O2)
add_definitions(-std=c++11)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(common)

#install(
#  DIRECTORY "${CMAKE_SOURCE_DIR}/include/client"
#  DESTINATION "${CMAKE_INCLUDE_CURRENT_DIR}/client"
#)
#
#install(
#  DIRECTORY "${CMAKE_SOURCE_DIR}/include/server"
#  DESTINATION "${CMAKE_INCLUDE_CURRENT_DIR}/server"
#)
#
#install(
#  DIRECTORY "${CMAKE_SOURCE_DIR}/include/comon"
#  DESTINATION "${CMAKE_INCLUDE_CURRENT_DIR}/comon"
#)
