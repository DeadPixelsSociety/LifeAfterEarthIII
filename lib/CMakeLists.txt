# Common library
# List of sources
file(GLOB LIBCOMMON_SOURCES "common/*.cc")

add_library(lae3common SHARED
  ${LIBCOMMON_SOURCES}
)

target_link_libraries(lae3common
  ${SFML2_LIBRARIES}
  sfml-network
  ${Boost_LIBRARIES}
)

set_target_properties(lae3common
  PROPERTIES
  VERSION ${CPACK_PACKAGE_VERSION}
  SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR}
)

install(
  TARGETS lae3common
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

# Client library
# List of sources
file(GLOB LIBCLIENT_SOURCES "client/*.cc")

add_library(lae3client SHARED
  ${LIBCLIENT_SOURCES}
)

target_link_libraries(lae3client
  ${SFML2_LIBRARIES}
  sfml-network
)

set_target_properties(lae3client
  PROPERTIES
  VERSION ${CPACK_PACKAGE_VERSION}
  SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR}
)

install(
  TARGETS lae3client
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

# Server library
# List of sources
file(GLOB LIBCLIENT_SOURCES "server/*.cc")

add_library(lae3server SHARED
  ${LIBCLIENT_SOURCES}
)

target_link_libraries(lae3server
  ${SFML2_LIBRARIES}
  sfml-network
)

set_target_properties(lae3server
  PROPERTIES
  VERSION ${CPACK_PACKAGE_VERSION}
  SOVERSION ${CPACK_PACKAGE_VERSION_MAJOR}
)

install(
  TARGETS lae3server
  LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
)

