cmake_minimum_required(VERSION 3.21)
project(rosetta)
file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)
file(GLOB_RECURSE CPP_TESTS tests/*.cpp)

set(CMAKE_CXX_STANDARD 23)
find_package(Boost REQUIRED thread locale)
find_package(fmt CONFIG REQUIRED)
find_package(sahara REQUIRED)
find_package(libmysql REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)
include_directories(D:/Workspace/Cpp/libsahara/include)

add_library(rosetta ${CPP_HEADERS} ${CPP_SOURCES})
target_link_libraries(rosetta PRIVATE Boost::thread fmt::fmt-header-only Boost::locale ${MYSQL_LIBRARIES} sahara::sahara)

file(GLOB_RECURSE TEST_HEADERS test/*.h test/*.hpp)
file(GLOB_RECURSE TEST_SOURCES test/*.cpp test/*.cc)
add_executable(rosetta_test ${TEST_HEADERS} ${TEST_SOURCES} )
target_link_libraries(rosetta_test PRIVATE rosetta )


