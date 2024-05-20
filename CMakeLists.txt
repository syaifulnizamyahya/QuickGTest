cmake_minimum_required(VERSION 3.5.0)
project(QuickGTest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(QuickGTest main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(googletest) # add googletest subdirectory
include_directories(googletest/include) # this is so we can #include <gtest/gtest.h>
target_link_libraries(QuickGTest PRIVATE gtest) # link google test to this executable

include(GoogleTest)
gtest_discover_tests(QuickGTest) # discovers tests by asking the compiled test executable to enumerate its tests