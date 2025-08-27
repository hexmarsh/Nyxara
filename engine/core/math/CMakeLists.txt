find_package(glm CONFIG REQUIRED)

add_library(nyxara_core_math INTERFACE)

target_link_libraries(nyxara_core_math
	INTERFACE
		glm::glm
)
