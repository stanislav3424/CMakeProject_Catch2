# CMake project for CMakeProject_Catch2
cmake_minimum_required(VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("CMakeProject_Catch2")

# Fetch Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.1
)
FetchContent_MakeAvailable(Catch2)

# Add main project executable
add_executable(CMakeProject_Catch2 "CMakeProject_Catch2.cpp" "CMakeProject_Catch2.h")

set_property(TARGET CMakeProject_Catch2 PROPERTY CXX_STANDARD 20)

# Link Catch2 for tests
target_link_libraries(CMakeProject_Catch2 PRIVATE Catch2::Catch2WithMain)

# Add test executable
add_executable(run_tests "test.cpp")
target_link_libraries(run_tests PRIVATE Catch2::Catch2WithMain)

# Enable testing
include(CTest)
add_test(NAME Catch2Tests COMMAND run_tests)
