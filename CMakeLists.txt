cmake_minimum_required(VERSION 3.11)

option(NYXARA_BUILD_DOCS "Set to ON to build docs" ON)

include(cmake/bootstrap-vcpkg.cmake)

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
        "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>"
    )
endif()

project(Nyxara VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(src/nyxara/core/logging)
add_subdirectory(apps)
add_subdirectory(docs)
