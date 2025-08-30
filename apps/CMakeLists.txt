add_executable(nyxara nyxara.cpp)

target_link_libraries(nyxara
    PRIVATE
        nyxara_core_logging
        nyxara_platform
        nyxara_renderer_vulkan
)
