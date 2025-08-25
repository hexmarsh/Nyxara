cmake_minimum_required(VERSION 3.11)

# use vcpkg's toolchain file
set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("Nyxara" 
	VERSION		0.1.0
	LANGUAGES	CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Add the executable target
add_executable(Nyxara 
	"src/Nyxara.cpp" 
	src/engine/logger.h
	src/engine/logger.cpp
)

find_package(spdlog CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

# Link dependencies
target_link_libraries(Nyxara PRIVATE spdlog::spdlog glm::glm)
