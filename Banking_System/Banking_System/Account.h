#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <ctime> 
class Account
{
private:
	long int accountID;
	static long double m_balance;
public:
	static long int globalAccountID;
	Account();
	~Account();
	void deposite(const double& amount);
	void withdraw(const double& amount);
	long int getAccountID(void) const;
	long double getAccountBalance(void) const;
	void setAccountID(const int& ID); 
	bool operator == (const Account& account) const;
};

