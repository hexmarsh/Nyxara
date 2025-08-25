find_package(glm CONFIG REQUIRED)

add_library(nyxara_math INTERFACE)

target_sources(nyxara_math 
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/transform.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/types.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/utils.h
		${CMAKE_CURRENT_SOURCE_DIR}/include/nyxara/math/vector_opts.h
)

target_include_directories(nyxara_math
	INTERFACE
		${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(nyxara_math
	INTERFACE
		glm::glm
)
