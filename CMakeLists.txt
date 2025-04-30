cmake_minimum_required(VERSION 3.14)
project(ATCPP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)


add_library(ATCPPlib lib/my_vector.cpp)
add_library(ATTCPPlib lib/type_templates.cpp)
include_directories(include)
add_executable(ATCPP src/main.cpp)

target_link_libraries(ATCPP ATCPPlib)

enable_testing()

add_executable(tests test/vector_test.cpp test/template_test.cpp)
target_link_libraries(tests GTest::gtest_main ATCPPlib)

include(GoogleTest)
gtest_discover_tests(tests)

