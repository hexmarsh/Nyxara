if(NOT NYXARA_BUILD_DOCS)
	return()
endif()

find_package(Doxygen REQUIRED)

if(NOT DOXYGEN_FOUND)
	message("Doxygen needs to be installed to generate the documentation.")
	return()
endif()

set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

add_custom_target(doc ALL
	COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
	WORKING_DIR ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Generating documentation with Doxygen..."
	VERBATIM
)