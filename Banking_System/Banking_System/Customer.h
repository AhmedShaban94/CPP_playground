#pragma once
#include <string>
#include <vector>
#include "Account.h"
class Customer
{
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_phoneNumber;
	long int customerID;
public:
	static long int globalCustomerID;
	Customer();
	~Customer();
	Customer(std::string firstName, std::string lastName, std::string phonenumber) :
		m_firstName{ firstName }, m_lastName{ lastName }, m_phoneNumber{ phonenumber }{}
	void setFirstName(const std::string& firstName);
	std::string getFirstName(void) const;
	void setlastName(const std::string& lastname);
	std::string getLastName(void) const;
	void setPhoneNumber(const std::string& phonenumber);
	std::string getPhoneNumber(void) const;
	long int getCustomerID(void)const;
	void setCustomerID(const int& ID);
};
