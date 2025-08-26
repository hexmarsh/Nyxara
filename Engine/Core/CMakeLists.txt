add_subdirectory(Logging)

add_library(NyxaraCore INTERFACE)

target_include_directories(NyxaraCore
	INTERFACE
		${CMAKE_SOURCE_DIR}/Engine/Core
)

target_link_libraries(NyxaraCore
	INTERFACE
		NyxaraLogging
)

