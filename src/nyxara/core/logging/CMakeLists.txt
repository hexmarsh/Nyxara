find_package(spdlog CONFIG REQUIRED)

add_library(nyxara_core_logging
	category.cpp
	categories.cpp
	logger.cpp
)

target_include_directories(nyxara_core_logging
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(nyxara_core_logging
	PUBLIC
		spdlog::spdlog
)
