cmake_minimum_required(VERSION 3.21)
project(rosetta)
set(CMAKE_CXX_STANDARD 20)
set(ROSETTA_VERSION 1.0.1)
include(CMakePackageConfigHelpers)

file(GLOB_RECURSE CPP_HEADERS include/*.h include/*.hpp)
file(GLOB_RECURSE CPP_SOURCES source/*.cpp source/*.cc)

find_package(Boost REQUIRED thread)
find_package(sahara REQUIRED)
find_package(libmysql REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(include)
include_directories(D:/Workspace/Cpp/libsahara/include)

add_library(rosetta STATIC ${CPP_HEADERS} ${CPP_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::thread fmt::fmt ${MYSQL_LIBRARIES} sahara::sahara)


configure_package_config_file(cmake/template/${PROJECT_NAME}.in.cmake
        ${PROJECT_NAME}-config.cmake
        INSTALL_DESTINATION ./)

write_basic_package_version_file(
        ${PROJECT_NAME}-config-version.cmake
        VERSION ${ROSETTA_VERSION}
        COMPATIBILITY ExactVersion)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        DESTINATION share/${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}-targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME} FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
install(EXPORT ${PROJECT_NAME}-targets NAMESPACE ${PROJECT_NAME}:: DESTINATION share/${PROJECT_NAME})

file(GLOB_RECURSE TEST_SOURCES test/*.h test/*.hpp test/*.cpp test/*.cc)
add_executable(${PROJECT_NAME}_test ${TEST_SOURCES} )
find_package(sahara REQUIRED)
find_package(Boost REQUIRED COMPONENTS json)
target_include_directories(${PROJECT_NAME}_test PRIVATE include)
target_link_libraries(${PROJECT_NAME}_test PRIVATE ws2_32 Boost::locale rosetta fmt::fmt)