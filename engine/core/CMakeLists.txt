add_subdirectory(Logging)

add_library(NyxaraCore INTERFACE)

target_link_libraries(NyxaraCore
	INTERFACE
		NyxaraLogging
		NyxaraMath
)

