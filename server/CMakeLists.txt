# List of sources
file(GLOB SERVER_SOURCES "*.cc")

add_executable(server
	${SERVER_SOURCES}
)

target_link_libraries(server 
	common
)
