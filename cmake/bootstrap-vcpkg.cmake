set(VCPKG_DIR "${CMAKE_SOURCE_DIR}/vcpkg" CACHE STRING "Path to the vcpkg directory")

if(WIN32)
    set(VCPKG_EXE "${VCPKG_DIR}/vcpkg.exe" CACHE STRING "Path to the vcpkg executable")
elseif(UNIX)
    set(VCPKG_EXE "${VCPKG_DIR}/vcpkg" CACHE STRING "Path to the vcpkg executable")
endif()

set(CMAKE_TOOLCHAIN_FILE "${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Path to the vcpkg cmake file")

if(EXISTS "${VCPKG_EXE}")
    message(STATUS "vcpkg already bootstrapped.")
    return()
endif()

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
