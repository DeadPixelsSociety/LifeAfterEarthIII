cmake_minimum_required(VERSION 2.8)

project(Life-After-Earth-III CXX)

include(CPackConfig.cmake)
include(GNUInstallDirs)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1 sfml-audio>=2.1)

add_definitions(-Wall -g -O2 -std=c++11)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory(src)
add_subdirectory(lib)

install(
  DIRECTORY "${CMAKE_SOURCE_DIR}/include/client"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lae3/client"
)

install(
  DIRECTORY "${CMAKE_SOURCE_DIR}/include/server"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lae3/server"
)

install(
  DIRECTORY "${CMAKE_SOURCE_DIR}/include/common"
  DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/lae3/common"
)
