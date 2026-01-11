cmake_minimum_required(VERSION 3.28)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
project(map_reduce VERSION ${PROJECT_VESRION})

set(CMAKE_CXX_STANDARD 17)

add_executable(map_reduce main.cpp)

option(WITH_BOOST_TEST "Whether to build Boost test" ON)

configure_file(version.h.in version.h)

if (MSVC)
    target_compile_options(map_reduce PRIVATE
            /W4
    )
    target_compile_options(map_reduce PRIVATE
            /W4
    )
    if(WITH_BOOST_TEST)
        target_compile_options(map_reduce PRIVATE
                /W4
        )
    endif()
else ()
    target_compile_options(map_reduce PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(map_reduce PRIVATE
            -Wall -Wextra -pedantic -Werror
    )
    if(WITH_BOOST_TEST)
        target_compile_options(map_reduce PRIVATE
                -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS map_reduce RUNTIME DESTINATION bin)

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
