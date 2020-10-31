#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE helloworld_test_module

#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <stdlib.h>
#include <boost/test/unit_test.hpp>
#include <boost/lexical_cast.hpp>

BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

BOOST_AUTO_TEST_CASE(helloworld_test_version)
{}

BOOST_AUTO_TEST_CASE(helloworld_test_build)
{}

BOOST_AUTO_TEST_SUITE_END()
