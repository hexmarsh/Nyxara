find_package(glfw3 CONFIG REQUIRED)

add_library(nyxara_platform
	window.cpp
	glfw_window.cpp
)

target_include_directories(nyxara_platform
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(nyxara_platform
	PUBLIC
		nyxara_core_logging
	PRIVATE
		glfw
)

