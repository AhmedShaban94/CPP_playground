#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Bank.h"
#include "Account.h"
#include <vector>


int main(int argc, char* argv[])
{
	auto bank = std::make_unique<Bank>();
	int choice;
	std::cout << "***** Banking System *****\n";
	do
	{
		std::cout << "\n\tEnter only one choice from the following:";
		std::cout << "\n\t1 Open an Account(Add new Customer)";
		std::cout << "\n\t2 Add an Account to a existing customer";
		std::cout << "\n\t3 Balance Enquiry";
		std::cout << "\n\t4 Deposite";
		std::cout << "\n\t5 Withdraw";
		std::cout << "\n\t6 Close an Account";
		std::cout << "\n\t7 Show all accounts";
		std::cout << "\n\t8 Show all customers";
		std::cout << "\n\t9 Quit";

		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::string firstName, lastName, phoneNumber;
			std::cout << "Enter First Name: \n";
			std::getline(std::cin, firstName);
			std::cout << "Enter Last Name: \n";
			std::getline(std::cin, lastName);
			std::cout << "Enter Phone Number: \n";
			std::getline(std::cin, phoneNumber);
			auto new_customer = std::make_unique<Customer>(firstName, lastName, phoneNumber);
			auto account = std::make_unique<Account>();
			bank->addAccount(new_customer.operator*(), account.operator*());
			break;
		}
		case 2:
		{
			std::string firstName, lastName, phoneNumber;
			std::cout << "Enter First Name: \n";
			std::getline(std::cin, firstName);
			std::cout << "Enter Last Name: \n";
			std::getline(std::cin, lastName);
			std::cout << "Enter Phone number: \n";
			std::getline(std::cin, phoneNumber);
			bank->addAccount(Customer(firstName, lastName, phoneNumber), *(new Account()));
			break;
		}
		case 3:
		{
			std::string firstName, lastName, phoneNumber;
			std::cout << "Enter First Name: \n";
			std::getline(std::cin, firstName);
			std::cout << "Enter Last Name: \n";
			std::getline(std::cin, lastName);
			std::cout << "Enter Phone number: \n";
			std::getline(std::cin, phoneNumber);
			Customer customer(firstName, lastName, phoneNumber);
			auto listOfAccounts = bank->listAccountsPerCustomer(customer);
			for (const auto& account : listOfAccounts)
				std::cout << account.getAccountID() << ": " << account.getAccountBalance() << " $\n";
			break;
		}
		case 4:
		{
			std::string firstName, lastName, phoneNumber;
			std::cout << "Enter First Name: \n";
			std::getline(std::cin, firstName);
			std::cout << "Enter Last Name: \n";
			std::getline(std::cin, lastName);
			std::cout << "Enter Phone number: \n";
			Customer customer(firstName, lastName, phoneNumber);
			auto listOfAccounts = bank->listAccountsPerCustomer(customer);
			std::cout << "Choose Account from the following Accounts\n";
			for (const auto& account : listOfAccounts)
				std::cout << account.getAccountID() << '\n';
			int accountChoice;
			bool found = false;
			for (auto& account : listOfAccounts)
			{
				if (account.getAccountID() == accountChoice)
				{
					long amount;
					std::cout << "Enter Amount: \n";
					std::cin >> amount;
					account.deposite(amount);
					found = true;
				}
				if (found) break;
			}
			if (!found) std::cout << "Invalid account ID was Entered\n";
			break;
		}
		default:
			std::cout << "\n\t Enter a valid choice";
			exit(0);
		}
	} while (choice != 9);

}

