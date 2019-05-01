#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Bank.h"
#include "Account.h"
#include <vector>
#include <exception>


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
		std::cout << "\n\t9 Quit\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			try
			{
				std::string firstName, lastName, phoneNumber;
				std::cout << "Enter First Name: \n";
				std::cin.ignore();
				std::getline(std::cin, firstName);
				std::cout << "Enter Last Name: \n";
				std::cin.ignore();
				std::getline(std::cin, lastName);
				std::cout << "Enter Phone Number: \n";
				std::cin.ignore();
				std::getline(std::cin, phoneNumber);
				auto new_customer = std::make_unique<Customer>(firstName, lastName, phoneNumber);
				auto account = std::make_unique<Account>();
				bank->addCustomer(new_customer.operator*());  
				bank->addAccount(new_customer.operator*(), account.operator*());
				break;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(0);
			}

		}
		case 2:
		{
			try
			{
				std::string firstName, lastName, phoneNumber;
				std::cout << "Enter First Name: \n";
				std::cin.ignore();
				std::getline(std::cin, firstName);
				std::cout << "Enter Last Name: \n";
				std::cin.ignore();
				std::getline(std::cin, lastName);
				std::cout << "Enter Phone number: \n";
				std::cin.ignore();
				std::getline(std::cin, phoneNumber);
				bank->addAccount(Customer(firstName, lastName, phoneNumber), *(new Account()));
				break;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(1);
			}

		}
		case 3:
		{
			try
			{
				std::string firstName, lastName, phoneNumber;
				std::cout << "Enter First Name: \n";
				std::cin.ignore();
				std::getline(std::cin, firstName);
				std::cout << "Enter Last Name: \n";
				std::cin.ignore();
				std::getline(std::cin, lastName);
				std::cout << "Enter Phone number: \n";
				std::cin.ignore();
				std::getline(std::cin, phoneNumber);
				Customer customer(firstName, lastName, phoneNumber);
				auto listOfAccounts = bank->listAccountsPerCustomer(customer);
				for (const auto& account : listOfAccounts)
					std::cout << account.getAccountID() << ": " << account.getAccountBalance() << " $\n";
				break;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(2);
			}
		}
		case 4:
		{
			try
			{
				std::string firstName, lastName, phoneNumber;
				std::cout << "Enter First Name: \n";
				std::cin.ignore();
				std::getline(std::cin, firstName);
				std::cout << "Enter Last Name: \n";
				std::cin.ignore();
				std::getline(std::cin, lastName);
				std::cout << "Enter Phone number: \n";
				std::cin.ignore();
				Customer customer(firstName, lastName, phoneNumber);
				auto listOfAccounts = bank->listAccountsPerCustomer(customer);
				std::cout << "Choose Account from the following Accounts\n";
				for (const auto& account : listOfAccounts)
					std::cout << account.getAccountID() << '\n';
				int accountChoice;
				std::cout << "Enter account choice: \n";
				std::cin >> accountChoice;
				bool found = false;
				for (auto& account : listOfAccounts)
				{
					if (account.getAccountID() == accountChoice)
					{
						long amount;
						std::cout << "Enter Amount: \n";
						std::cin >> amount;
						bank->deposite(account, amount);
						found = true;
					}
					if (found) break;
				}
				if (!found) std::cout << "Invalid account ID was Entered\n";
				break;
			}
			catch (std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(3);
			}

		}
		case 5:
		{
			try
			{
				std::string firstName, lastName, phoneNumber;
				std::cout << "Enter First Name: \n";
				std::cin.ignore();
				std::getline(std::cin, firstName);
				std::cout << "Enter Last Name: \n";
				std::cin.ignore();
				std::getline(std::cin, lastName);
				std::cout << "Enter Phone number: \n";
				std::cin.ignore();
				Customer customer(firstName, lastName, phoneNumber);
				auto listOfAccounts = bank->listAccountsPerCustomer(customer);
				std::cout << "Choose Account from the following Accounts\n";
				for (const auto& account : listOfAccounts)
					std::cout << account.getAccountID() << '\n';
				int accountChoice;
				std::cout << "Enter account choice: \n";
				std::cin >> accountChoice;
				bool found = false;
				for (auto& account : listOfAccounts)
				{
					if (account.getAccountID() == accountChoice)
					{
						long amount;
						std::cout << "Enter Amount: \n";
						std::cin >> amount;
						bank->withdraw(account, amount);
						found = true;
					}
					if (found) break;
				}
				if (!found) std::cout << "Invalid account ID was Entered\n";
				break;
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(4);
			}
		}
		case 6:
		{
			try
			{
				std::string firstName, lastName, phoneNumber;
				std::cout << "Enter First Name: \n";
				std::cin.ignore();
				std::getline(std::cin, firstName);
				std::cout << "Enter Last Name: \n";
				std::cin.ignore();
				std::getline(std::cin, lastName);
				std::cout << "Enter Phone number: \n";
				std::cin.ignore();
				Customer customer(firstName, lastName, phoneNumber);
				auto listOfAccounts = bank->listAccountsPerCustomer(customer);
				std::cout << "Choose Account from the following Accounts\n";
				for (const auto& account : listOfAccounts)
					std::cout << account.getAccountID() << '\n';
				int accountChoice;
				std::cout << "Enter account choice: \n";
				std::cin >> accountChoice;
				bool found = false;
				for (auto& account : listOfAccounts)
				{
					if (account.getAccountID() == accountChoice)
					{
						bank->removeAccount(customer, account);
						found = true;
					}
					if (found) break;
				}
				if (!found) std::cout << "Invalid account ID was Entered\n";
				break;
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(5);
			}

		}
		case 7:
		{
			try
			{
				for (const auto& customer : bank->listCustomers())
				{
					for (const auto& account : bank->listAccountsPerCustomer(customer))
						std::cout << account.getAccountID() << ": " << account.getAccountBalance() << '\n';
				}
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(6);
			}

		}
		case 8:
		{
			try
			{
				for (const auto& customer : bank->listCustomers())
				{
					std::cout << "Customer ID: " << customer.getCustomerID() << '\n';
					std::cout << "Customer Name: " << customer.getFirstName() << " " << customer.getLastName() << '\n';
					std::cout << "Phone number: " << customer.getPhoneNumber() << '\n';
				}
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << '\n';
				exit(7);
			}

		}
		default:
			std::cout << "\n\t Enter a valid choice";
			exit(0);
		}
	} while (choice != 9);
}

