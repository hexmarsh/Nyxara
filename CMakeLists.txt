cmake_minimum_required(VERSION 3.11)

# --------------------------
# Bootstrap vcpkg if needed
# --------------------------

set(VCPKG_DIR "${CMAKE_SOURCE_DIR}/vcpkg")
set(VCPKG_EXE "${VCPKG_DIR}/vcpkg")

if(NOT EXISTS "${VCPKG_EXE}")
    message(STATUS "vcpkg executable not found. Attempting to bootstrap...")

    if(WIN32)
        message(STATUS "Detected Windows. Running bootstrap-vcpkg.bat...")
        execute_process(
            COMMAND cmd /c bootstrap-vcpkg.bat
            WORKING_DIRECTORY "${VCPKG_DIR}"
            RESULT_VARIABLE _vcpkg_result
        )
    elseif(UNIX)
        message(STATUS "Detected Unix-like OS. Making bootstrap script executable...")
        execute_process(
            COMMAND chmod +x bootstrap-vcpkg.sh
            WORKING_DIRECTORY "${VCPKG_DIR}"
        )

        message(STATUS "Running bootstrap-vcpkg.sh...")
        execute_process(
            COMMAND bash ./bootstrap-vcpkg.sh
            WORKING_DIRECTORY "${VCPKG_DIR}"
            RESULT_VARIABLE _vcpkg_result
        )
    endif()

    if(NOT _vcpkg_result EQUAL 0)
        message(FATAL_ERROR "Failed to bootstrap vcpkg (exit code: ${_vcpkg_result})")
    else()
        message(STATUS "Successfully bootstrapped vcpkg.")
    endif()
else()
    message(STATUS "vcpkg already bootstrapped.")
endif()

# -------------------------------------
# Use vcpkg toolchain for dependency resolution
# -------------------------------------
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# --------------------------
# Compiler Configuration
# --------------------------

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
        "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>"
    )
endif()

# --------------------------
# Project Setup
# --------------------------

project(Nyxara
    VERSION 0.1.0
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Add subdirectories
add_subdirectory(Engine)
