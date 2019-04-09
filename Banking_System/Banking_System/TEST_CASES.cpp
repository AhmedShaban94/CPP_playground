#define USE_TEST_CASES
#ifdef USE_TEST_CASES	

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Bank.h"
#include "Account.h"
#include "Customer.h"

#include <memory>
#include <vector>

TEST_CASE("Test Bank class")
{
	auto bank = std::make_unique<Bank>();


	SECTION("Add Customer")
	{
		auto customer = std::make_unique<Customer>("Ahmed", "Shaban", "12345");
		bank->addCustomer(customer.operator*());
		auto customers = bank->listCustomers();
		REQUIRE(customers[0].getFirstName() == "Ahmed");
		REQUIRE(customers[0].getLastName() == "Shaban");
		REQUIRE(customers[0].getPhoneNumber() == "12345");
		REQUIRE(customers[0].getCustomerID() == 1);
		REQUIRE(Customer::globalCustomerID == 1);
	}

	SECTION("remove customer")
	{
		auto customer = std::make_unique<Customer>("Ahmed", "Shaban", "01097206301");
		bank->removeCustomer(customer.operator*());
		REQUIRE(bank->listCustomers().empty() == true);
	}
}

#endif