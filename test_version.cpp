#define BOOST_TEST_MODULE helloworld_test_module

#include "lib.h"

#include <iostream>
#include <stdlib.h>
#include <boost/test/unit_test.hpp>
#include <boost/lexical_cast.hpp>

BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

BOOST_AUTO_TEST_CASE(helloworld_test_version)
{
	BOOST_TEST_MESSAGE("Version: " << boost::lexical_cast<std::string>(version()) << ";");
}

BOOST_AUTO_TEST_CASE(helloworld_test_build)
{
	auto *travis_build_number_as_str = getenv("TRAVIS_BUILD_NUMBER");
	BOOST_TEST_MESSAGE("Build number: " << travis_build_number_as_str << ";");
}

BOOST_AUTO_TEST_SUITE_END()
