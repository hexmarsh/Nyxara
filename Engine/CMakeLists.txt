add_subdirectory(Core)

add_executable(NyxaraEngine Nyxara.cpp)

target_include_directories(NyxaraEngine
    PRIVATE
        ${CMAKE_SOURCE_DIR}
)

target_link_libraries(NyxaraEngine
    PRIVATE
        NyxaraCore
)

