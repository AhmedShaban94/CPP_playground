#include "Account.h"
#include <iostream>
long int Account::globalAccountID = 0;
long double Account::m_balance = 0;

Account::Account()
{
	accountID = NULL; 
}

Account::~Account() = default;

void Account::deposite(const double& amount)
{
	this->m_balance += amount;
}

void Account::withdraw(const double& amount)
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

void Account::setAccountID(const int& ID)
{
	accountID = ID;
}


bool Account::operator==(const Account& account1) const
{
	return this->getAccountID() == account1.getAccountID();
}



