#include "Customer.h"

long int Customer::globalCustomerID = 0;

Customer::Customer() { }

Customer::~Customer() = default;

void Customer::setFirstName(const std::string& firstName)
{
	this->m_firstName = firstName;
}

std::string Customer::getFirstName(void) const
{
	return this->m_firstName;
}

void Customer::setlastName(const std::string& lastname)
{
	this->m_lastName = lastname;
}

std::string Customer::getLastName(void) const
{
	return this->m_lastName;
}

void Customer::setPhoneNumber(const std::string& phonenumber)
{
	this->m_phoneNumber = phonenumber;
}

std::string Customer::getPhoneNumber(void) const
{
	return this->m_phoneNumber;
}

long int Customer::getCustomerID(void) const
{
	return this->customerID;
}

void Customer::setCustomerID(const int& ID)
{
	customerID = ID;
}
