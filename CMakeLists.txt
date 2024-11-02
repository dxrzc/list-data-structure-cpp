cmake_minimum_required(VERSION 3.5)

project(testing)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB SOURCES 
"testing/constructors/*.cpp"
"testing/helpers/*.cpp"
"testing/iterators/*.cpp"
"testing/methods/*.cpp"
)

add_executable(testing
	${SOURCES}
)

target_include_directories(testing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

target_link_libraries(
  testing
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(testing)
