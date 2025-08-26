find_package(spdlog CONFIG REQUIRED)

add_library(nyxara_logging
	include/nyxara/logging/logger.h
	src/logging/logger.cpp
	include/nyxara/logging/macros.h
	include/nyxara/logging/function_tracer.h
	include/nyxara/logging/verbosity.h
	include/nyxara/logging/category.h
	include/nyxara/logging/categories.h
	include/nyxara/logging/call_depth.h
	src/logging/category.cpp
)

target_include_directories(nyxara_logging
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(nyxara_logging
	PUBLIC
		spdlog::spdlog
)
