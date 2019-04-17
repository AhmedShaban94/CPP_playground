#include "Account.h"

long int Account::globalAccountID = 0;
long double Account::m_balance = 0;

Account::Account()
{
	std::cout << "New Account is Open\n";  
	globalAccountID++;
	this->accountID = globalAccountID;
	std::time_t t = std::time(nullptr);
	this->m_openTime = std::localtime(&t);
}

Account::~Account()
{
	std::cout << "Account Deleted\n";
}

void Account::deposite(const double amount)
{
	this->m_balance += amount;
}

void Account::withdraw(const double amount)
{
	this->m_balance -= amount;
}

long double Account::getAccountBalance() const
{
	return this->m_balance;
}


long Account::getAccountID() const
{
	return this->accountID;
}

bool Account::operator==(const Account& account1) const
{
	return this->getAccountID() == account1.getAccountID();
}



