add_executable(nyxara_engine Nyxara.cpp)

target_include_directories(nyxara_engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

find_package(glm CONFIG REQUIRED)

target_link_libraries(nyxara_engine
    PRIVATE
        nyxara_core
        glm::glm
)

