find_package(spdlog CONFIG REQUIRED)

add_library(NyxaraLogging
		include/nyxara/core/logging/call_depth_manager.h
		include/nyxara/core/logging/category.h
		include/nyxara/core/logging/categories.h
		include/nyxara/core/logging/function_tracer.h
		include/nyxara/core/logging/logger.h
		include/nyxara/core/logging/macros.h
		include/nyxara/core/logging/verbosity.h
 )

 target_sources(NyxaraLogging
	PRIVATE
		src/category.cpp
		src/logger.cpp
 )

target_include_directories(NyxaraLogging
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(NyxaraLogging
	PUBLIC
		spdlog::spdlog
)
