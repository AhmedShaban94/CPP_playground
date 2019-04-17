#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Bank.h"
#include "Account.h"

int main(int argc, char* argv[])
{
	auto result = Catch::Session().run(argc, argv);
	auto bank = std::make_unique<Bank>();
	auto customer = std::make_unique<Customer>("Ahmed", "Shaabn", "123");
	auto account = std::make_unique<Account>();
	bank->addCustomer(customer.operator*());
	bank->addAccount(customer.operator*(), account.operator*());
	auto customerList = bank->listCustomers();
	auto accountList = bank->listAccountsPerCustomer(customer.operator*());
	std::cout << customerList.size() << '\n';
	std::cout << accountList.size() << '\n';
	auto customer2 = std::make_unique<Customer>("Mohamed", "Ahmed", "111");
	auto account2 = std::make_unique<Account>();
	bank->addCustomer(customer2.operator*());
	bank->addAccount(customer2.operator*(), account2.operator*());
	std::cout << bank->listCustomers().size() << '\n';
	std::cout << bank->listAccountsPerCustomer(customer.operator*()).size() << '\n';
	return result;
}

