find_package(glm CONFIG REQUIRED)

add_library(nyxara_math INTERFACE)

target_sources(nyxara_math 
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/vec1.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/vec2.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/vec3.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/vec4.h
)

target_include_directories(nyxara_math
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(nyxara_math
	INTERFACE
		glm::glm
)
