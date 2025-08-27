find_package(spdlog CONFIG REQUIRED)

add_library(nyxara_core_logging
		include/nyxara/core/logging/call_depth_manager.h
		include/nyxara/core/logging/category.h
		include/nyxara/core/logging/categories.h
		include/nyxara/core/logging/function_tracer.h
		include/nyxara/core/logging/logger.h
		include/nyxara/core/logging/macros.h
		include/nyxara/core/logging/verbosity.h
 )

 target_sources(nyxara_core_logging
	PRIVATE
		src/category.cpp
		src/logger.cpp
 )

target_include_directories(nyxara_core_logging
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(nyxara_core_logging
	PUBLIC
		spdlog::spdlog
)
