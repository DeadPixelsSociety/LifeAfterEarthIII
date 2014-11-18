# List of sources
file(GLOB CLIENT_SOURCES "*.cc")

add_executable(client
  ${CLIENT_SOURCES}
)

target_link_libraries(client
	lae3common
	sfml-audio
	sfml-network
	sfml-graphics
	sfml-window
	sfml-system
)

install(
  TARGETS client
  RUNTIME DESTINATION games/life-after-earth-3
)
