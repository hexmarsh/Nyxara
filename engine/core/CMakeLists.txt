add_subdirectory(logging)
add_subdirectory(math)

add_library(nyxara_core INTERFACE)

target_link_libraries(nyxara_core
	INTERFACE
		nyxara_core_logging
		nyxara_core_math
)

