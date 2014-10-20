# List of sources
file(GLOB LIBCOMMON_SOURCES "*.cc")

add_library(common SHARED
	${LIBCOMMON_SOURCES}
)

