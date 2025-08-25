find_package(spdlog CONFIG REQUIRED)

add_library(nyxara_logging
	include/nyxara/logging/logger.h
	include/nyxara/logging/logger.cpp
)

target_include_directories(nyxara_logging
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(nyxara_logging
	PUBLIC
		spdlog::spdlog
)
