#include "Account.h"

long int Account::accountID = 0;
long double Account::m_balance = 0;

Account::Account()
{
	accountID++;
	std::time_t t = std::time(0);
	m_openTime = std::localtime(&t);
}

Account::~Account()
{
	std::time_t t = std::time(0);
	m_closeTime = std::localtime(&t);
}

void Account::deposite(const double amount)
{
	m_balance += amount;
}

void Account::withdraw(const double amount)
{
	m_balance -= amount;
}

long double Account::getAccountBalance() const
{
	return this->m_balance; 
}

long Account::getAccountID() const
{
	return this->accountID; 
}


