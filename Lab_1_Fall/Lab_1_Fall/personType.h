#pragma once
#include <string>
using namespace std;
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
	private:
		std::string interest1, interest2;
};

