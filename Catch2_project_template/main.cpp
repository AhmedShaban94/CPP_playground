#define RUN_TESTS 
#ifdef RUN_TESTS
#define CATCH_CONFIG_RUNNER
#include "TEST_CASES.hpp"
#include <catch.hpp>
#endif


int main(int argc, char* argv[])
{
	auto result = 0;
#ifdef RUN_TESTS
	result = Catch::Session().run(argc, argv);
#else 
	// main code goes here. 
#endif 
	std::cin.get();
	return result;
}
