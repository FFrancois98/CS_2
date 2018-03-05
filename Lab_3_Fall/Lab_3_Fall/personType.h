#pragma once
#include <string>
using namespace std;

class contact_infoType
{
public:
	string get_emailAddress;
private:
	string emailAddress;
	string phoneNumber;
	string userName;
	string password;
};

class addressType {
public:
	int streetAddressNum, zipCode;
	std::string streetName, streetType, city, stateInitials;
	addressType();
};
class personType {
public:
	std::string lastName, firstName;
	int personNum, personID;
	char gender;
	addressType address;
	void setInterest1(std::string);
	void setInterest2(std::string);
	std::string getInterest1() const;
	std::string getInterest2() const;
	personType();
	void printPerson();
protected:
	contact_infoType contactInfo;
private:
	std::string interest1, interest2;
};
//define membershipType class 
class membershipType :public personType
{
public:
	char membership_type;
	char membership_status;
	membershipType();  // 1st constructor
	membershipType(char, char);  // 2nd constructor
	void print_member_type();
};
