#pragma once
#include <unordered_map>
#include <vector>
#include <map>
#include <iostream>
#include "Customer.h"
#include "Account.h"
class Bank
{
private:
	struct customerCompare
	{
		bool operator () (Customer lhs, Customer rhs) const
		{
			return lhs.getCustomerID() < rhs.getCustomerID();
		}
	};
	std::map<Customer, std::vector<Account>, customerCompare> customerAccountsMap;
public:
	Bank();
	~Bank();
	void addCustomer(const Customer& customer);
	bool removeCustomer(Customer& customer);
	void addAccount(const Customer& customer, const Account & account);
	void removeAccount(const Customer& customer, Account & account);
	void deposite(Account& account, const double amount);
	void withdraw(Account& account, const double amount);
	std::vector<Customer> listCustomers(void);
};

