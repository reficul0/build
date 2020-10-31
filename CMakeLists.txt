cmake_minimum_required(VERSION 3.2)

project(cmake)

set(Boost_DEBUG ON)

 # if(CMAKE_SIZEOF_VOID_P EQUAL 8)
	# set(Boost_ARCHITECTURE "-x86")
    # # set(Boost_LIBRARY_DIR ${BOOST_ROOT}/stage64/lib)
 # elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
	# set(Boost_ARCHITECTURE "-x64")
    # # set(Boost_LIBRARY_DIR ${BOOST_ROOT}/stage/lib)
 # endif()

find_package(Threads REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(helloworld_cli main.cpp)

add_executable(test_version test_version.cpp)

set_target_properties(helloworld_cli test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli
    Threads::Threads
)

target_link_libraries(test_version
    ${Boost_LIBRARIES}
)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT cheshirwr@mail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(helloworld_tests test_version)
