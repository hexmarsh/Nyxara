add_executable(nyxara_engine Nyxara.cpp)

target_include_directories(nyxara_engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(nyxara_engine
    PRIVATE
        nyxara_core
)

