#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <numeric> 
#include <unordered_map>
#include <ctime> 
class Account
{
private:
	static long int accountID;
	static long double m_balance;
	std::tm* m_openTime;
	std::tm* m_closeTime;
public:
	Account();
	~Account();
	void deposite(const double amount);
	void withdraw(const double amount);
	long int getAccountID(void) const;
	long double getAccountBalance(void) const;
};

