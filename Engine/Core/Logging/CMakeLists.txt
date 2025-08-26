find_package(spdlog CONFIG REQUIRED)

add_library(NyxaraLogging
		${CMAKE_CURRENT_SOURCE_DIR}/CallDepthManager.h
		${CMAKE_CURRENT_SOURCE_DIR}/Categories.h
		${CMAKE_CURRENT_SOURCE_DIR}/Category.h
		${CMAKE_CURRENT_SOURCE_DIR}/FunctionTracer.h
		${CMAKE_CURRENT_SOURCE_DIR}/Logger.h
		${CMAKE_CURRENT_SOURCE_DIR}/Macros.h
		${CMAKE_CURRENT_SOURCE_DIR}/Verbosity.h
		${CMAKE_CURRENT_SOURCE_DIR}/Private/Category.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/Private/Logger.cpp
)

target_include_directories(NyxaraLogging
	PUBLIC
		${CMAKE_SOURCE_DIR}
	PRIVATE
		${CMAKE_SOURCE_DIR}/Engine/Core/Logging/Private
)

target_link_libraries(NyxaraLogging
	PUBLIC
		spdlog::spdlog
)
