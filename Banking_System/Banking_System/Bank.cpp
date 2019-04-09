#include "Bank.h"

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::addCustomer(const Customer & customer)
{
	customerAccountsMap.insert(std::make_pair(customer, std::vector<Account>()));
}

bool Bank::removeCustomer(Customer & customer)
{
	return customerAccountsMap.erase(customer);
}

void Bank::addAccount(const Customer& customer, const Account & account)
{
	auto& accounts = customerAccountsMap.at(customer);
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
