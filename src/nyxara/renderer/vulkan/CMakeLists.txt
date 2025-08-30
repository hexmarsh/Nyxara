find_package(Vulkan REQUIRED)

add_library(nyxara_renderer_vulkan INTERFACE)

target_include_directories(nyxara_renderer_vulkan

	INTERFACE
		${Vulkan_INCLUDE_DIR}
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(nyxara_renderer_vulkan
	INTERFACE
		Vulkan::Vulkan
)
