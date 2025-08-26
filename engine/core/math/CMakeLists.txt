find_package(glm CONFIG REQUIRED)

add_library(NyxaraMath)

target_link_libraries(NyxaraMath
	PUBLIC
		glm::glm
)
