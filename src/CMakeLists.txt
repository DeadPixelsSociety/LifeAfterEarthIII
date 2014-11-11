# Client application
# List of sources
file(GLOB CLIENT_SOURCES "client/*.cc")

add_executable(lae3-client
  ${CLIENT_SOURCES}
)

target_link_libraries(lae3-client
	lae3common
	lae3client
)

install(
  TARGETS lae3-client
  RUNTIME DESTINATION games/life-after-earth-3
)

# Server application
# List of sources
file(GLOB SERVER_SOURCES "server/*.cc")

add_executable(lae3-server
  ${SERVER_SOURCES}
)

target_link_libraries(lae3-server
	lae3common
	lae3client
)

install(
  TARGETS lae3-server
  RUNTIME DESTINATION games/life-after-earth-3
)
