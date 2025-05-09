cmake_minimum_required(VERSION 3.5)

project(testing)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE TEST_SOURCES "testing/**/*.cpp")

add_executable(testing
	${TEST_SOURCES}
)

target_include_directories(
	testing 
	PRIVATE 
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/testing/helpers/include
	${CMAKE_CURRENT_SOURCE_DIR}/testing/iterators/setup/include
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
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
