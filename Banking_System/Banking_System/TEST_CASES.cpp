#define USE_TEST_CASES	
#ifdef USE_TEST_CASES

/*Third-party includes*/
#include "catch.hpp"

/*User-defined includes*/
#include "Bank.h"
#include "Account.h"
#include "Customer.h"

/*Standard includes*/
#include <memory>
#include <vector>

TEST_CASE("Test Bank class")
{
	auto bank = std::make_unique<Bank>();
	auto customer = std::make_unique<Customer>("Ahmed", "Shaban", "12345");
	auto account = std::make_unique<Account>();
	bank->addAccount(customer.operator*(), account.operator*()); 

	SECTION("Add Customer")
	{
		// Add first customer. 
		bank->addCustomer(customer.operator*());
		auto customers = bank->listCustomers();
		REQUIRE(customers.size() == 1);
		REQUIRE(customers[0].getFirstName() == "Ahmed");
		REQUIRE(customers[0].getLastName() == "Shaban");
		REQUIRE(customers[0].getPhoneNumber() == "12345");
		REQUIRE(customers[0].getCustomerID() == 1);
		REQUIRE(Customer::globalCustomerID == 1);

		// Add second customer
		auto customer2 = std::make_unique<Customer>("Mohamed", "Ahmed", "152424");
		bank->addCustomer(customer2.operator*());
		customers = bank->listCustomers();
		REQUIRE(customers.size() == 2);
		REQUIRE(customers[1].getFirstName() == "Mohamed");
		REQUIRE(customers[1].getLastName() == "Ahmed");
		REQUIRE(customers[1].getPhoneNumber() == "152424");
		REQUIRE(customers[1].getCustomerID() == 2);
		REQUIRE(Customer::globalCustomerID == 2);
	}

	SECTION("Remove Customer")
	{
		auto customer = std::make_unique<Customer>("Ahmed", "Shaban", "1234567");
		bank->removeCustomer(customer.operator*());
		REQUIRE(bank->listCustomers().empty() == true);
	}

	SECTION("Add Account")
	{
		/*
		 * not working as a test case yet, to be investigated further.  
		// Add first account. 
		bank->addAccount(customer.operator*(), account.operator*());
		REQUIRE(bank->listAccountsPerCustomer(customer.operator*()).size() == 1);

		// Add second account. 
		auto account2 = std::make_unique<Account>();
		bank->addAccount(customer.operator*(), account2.operator*());
		REQUIRE(bank->listAccountsPerCustomer(customer.operator*()).size() == 2); 
		*/
	}

	SECTION("Remove account")
	{
		bank->removeAccount(customer.operator*(), account.operator*());
		REQUIRE(bank->listAccountsPerCustomer(customer.operator*()).size() == 0); 
	}

	SECTION("Deposit")
	{

	}

	SECTION("Withdraw")
	{

	}

	SECTION("List Customers")
	{

	}
}

#endif