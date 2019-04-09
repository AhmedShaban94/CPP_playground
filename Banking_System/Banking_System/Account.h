#pragma once
#define _CRT_SECURE_NO_WARNINGS
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
	long int accountID;
	static long double m_balance;
	std::tm* m_openTime;
	std::tm* m_closeTime;
public:
	static long int globalAccountID;
	Account();
	~Account();
	void deposite(const double amount);
	void withdraw(const double amount);
	long int getAccountID(void) const;
	long double getAccountBalance(void) const;
	bool operator == (const Account& account) const;
};

