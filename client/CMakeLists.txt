include_directories("${SFML2_INCLUDE_DIRS}")

# List of sources
file(GLOB CLIENT_SOURCES "*.cc")

add_executable(client
  ${CLIENT_SOURCES}
)

target_link_libraries(client
	lae3common
	${SFML2_LIBRARIES}
)

install(
  TARGETS client
  RUNTIME DESTINATION games/life-after-earth-3
)
