#pragma once
//#define RUN_TESTS
#ifdef RUN_TESTS 
#include <catch.hpp>

TEST_CASE("this is a test")
{
	REQUIRE(5 == 5);
}
#endif 
