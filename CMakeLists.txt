cmake_minimum_required(VERSION 3.28)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(map_reduce VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 17)

add_executable(mapper_mean mappermean.cpp)
add_executable(reducer_mean reducermean.cpp)
add_executable(mapper_variance mappervariance.cpp)
add_executable(reducer_variance reducervariance.cpp)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

configure_file(version.h.in version.h)

install(TARGETS mapper_mean reducer_mean mapper_variance reducer_variance RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_BOOST_TEST)
    enable_testing()
    add_test(map_reduce map_reduce)
endif()
