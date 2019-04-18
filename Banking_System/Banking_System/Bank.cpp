#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::addCustomer(Customer & customer)
{
	customer.setCustomerID(Customer::globalCustomerID++);
	customerAccountsMap.insert(std::make_pair(customer, std::vector<Account>()));
}

bool Bank::removeCustomer(Customer & customer)
{
	return customerAccountsMap.erase(customer);
}

void Bank::addAccount(const Customer& customer, Account & account)
{
	auto& accounts = customerAccountsMap.at(customer);
	account.setAccountID(Account::globalAccountID++);
	accounts.push_back(account);
}

void Bank::removeAccount(const Customer& customer, Account & account)
{
	auto& accounts = customerAccountsMap.at(customer);
	accounts.erase(std::remove(accounts.begin(), accounts.end(), account), accounts.end());
}

void Bank::deposite(Account & account, const double amount)
{
	account.deposite(amount);
}

void Bank::withdraw(Account & account, const double amount)
{
	account.withdraw(amount);
}

std::vector<Customer> Bank::listCustomers()
{
	std::vector<Customer> customers;
	for (const auto& customer : customerAccountsMap)
		customers.push_back(customer.first);
	return customers;
}

std::vector<Account> Bank::listAccountsPerCustomer(const Customer& customer)
{
	auto iter = customerAccountsMap.find(customer);
	return iter->second;
}
