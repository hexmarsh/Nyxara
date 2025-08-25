add_subdirectory(logging)

add_library(nyxara_core INTERFACE)

target_link_libraries(nyxara_core
	INTERFACE
		nyxara_logging
)