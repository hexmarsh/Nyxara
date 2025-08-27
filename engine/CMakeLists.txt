add_subdirectory(core)

add_executable(nyxara nyxara.cpp)

target_include_directories(nyxara
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(nyxara
    PRIVATE
        nyxara_core
)
