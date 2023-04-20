cmake_minimum_required(VERSION 3.14)
project(snake)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

find_library(CURSES_LIBRARY curses)

include_directories(src)
aux_source_directory(src SRC)

add_executable(
  snake
  ./Main.cpp
  ${SRC}
)
include_directories(
  ./include
)
target_link_libraries(
  snake
  ${CURSES_LIBRARY}
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(test)
aux_source_directory(test TEST)

add_executable(
  hello_test
  ${TEST}
  ${SRC}
)
target_link_libraries(
  hello_test
  GTest::gtest_main
  ${CURSES_LIBRARY}
)

include(GoogleTest)
gtest_discover_tests(hello_test)