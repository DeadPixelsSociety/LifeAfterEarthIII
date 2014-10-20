# List of sources
file(GLOB CLIENT_SOURCES "*.cc")

add_executable(client
	${CLIENT_SOURCES}
)

target_link_libraries(client 
	common
)
