#include "Customer.h"



Customer::Customer() = default;

Customer::~Customer() = default;

void Customer::setFirstName(const std::string& firstName)
{
	this->m_firstName = firstName;
}

std::string Customer::getFirstName(void)
{
	return this->m_firstName;
}

void Customer::setlastName(const std::string& lastname)
{
	this->m_lastName = lastname;
}

std::string Customer::getLastName(void)
{
	return this->m_lastName;
}

void Customer::setPhoneNumber(const std::string& phonenumber)
{
	this->m_phoneNumber = phonenumber;
}

std::string Customer::getPhoneNumber(void)
{
	return this->m_phoneNumber;
}
