cmake_minimum_required(VERSION 3.22)
project(rosetta)
file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)
file(GLOB_RECURSE CPP_TESTS tests/*.cpp)

set(CMAKE_CXX_STANDARD 23)
find_package(Boost REQUIRED thread)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)
include_directories(D:/Workspace/Cpp/libsahara/include)
include_directories("C:\\Program Files\\MySQL\\MySQL Connector C++ 8.0\\include")
link_directories("C:/Program Files/MySQL/MySQL Connector C++ 8.0/debug/vs14")
if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    link_directories(D:/Workspace/Cpp/Rosetta/cmake-build-debug)
    link_directories(D:/Workspace/Cpp/libsahara/cmake-build-debug)
elseif (${CMAKE_BUILD_TYPE} MATCHES Release)
    link_directories(D:/Workspace/Cpp/Rosetta/cmake-build-release)
    link_directories(D:/Workspace/Cpp/libsahara/cmake-build-release)
endif()

add_library(rosetta ${CPP_HEADERS} ${CPP_SOURCES})
target_link_libraries(rosetta PRIVATE mysqlcppconn8 mysqlcppconn Boost::thread libsahara)

file(GLOB_RECURSE TEST_HEADERS test/*.h test/*.hpp)
file(GLOB_RECURSE TEST_SOURCES test/*.cpp test/*.cc)
add_executable(rosetta_test ${TEST_HEADERS} ${TEST_SOURCES} )
target_link_libraries(rosetta_test PRIVATE rosetta )


