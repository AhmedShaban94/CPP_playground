#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include "Customer.h"
#include "Account.h"
class Bank
{
private:
	struct customerCompare
	{
		bool operator () (const Customer& lhs, const Customer& rhs) const
		{
			return lhs.getCustomerID() < rhs.getCustomerID();
		}
	};
	std::map<Customer, std::vector<Account>, customerCompare> customerAccountsMap;
public:
	Bank();
	~Bank();
	void addCustomer(Customer& customer);
	bool removeCustomer(Customer& customer);
	void addAccount(const Customer& customer, Account & account);
	void removeAccount(const Customer& customer, Account & account);
	void deposite(Account& account, const double amount);
	void withdraw(Account& account, const double amount);
	std::vector<Customer> listCustomers(void);
	std::vector<Account> listAccountsPerCustomer(const Customer& customer);
};

