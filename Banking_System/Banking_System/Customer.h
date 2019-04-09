#pragma once
#include <string>
class Customer
{
private:
	std::string m_firstName;
	std::string m_lastName;
	std::string m_phoneNumber;
	static long customerID;
public:
	Customer();
	~Customer();
	Customer(std::string firstName, std::string lastName, std::string phonenumber) :
		m_firstName{ firstName }, m_lastName{ lastName }, m_phoneNumber{ phonenumber } {}
	void setFirstName(const std::string& firstName);
	std::string getFirstName(void);
	void setlastName(const std::string& lastname);
	std::string getLastName(void);
	void setPhoneNumber(const std::string& phonenumber);
	std::string getPhoneNumber(void);
};
