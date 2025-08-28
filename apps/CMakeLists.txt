add_executable(nyxara nyxara.cpp)

target_link_libraries(nyxara
    PRIVATE
        nyxara_core_logging
)
