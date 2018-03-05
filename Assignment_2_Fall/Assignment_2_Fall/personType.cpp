#include "personType.h"
#include <iostream>
std::string personType::getInterest1() const {
	return interest1;
}
std::string personType::getInterest2() const {
	return interest2;
}
void personType::setInterest1(std::string i1) {
	interest1 = i1;
}
void personType::setInterest2(std::string i2) {
	interest2 = i2;
}
void personType::printPerson() {
	cout << "Person Number: " << personNum << endl << "Name: " << lastName << " " << firstName << endl
		<< "ID: " << personID << endl << "Address: " << address.streetAddressNum << " " << address.streetName
		<< " " << address.streetType << " " << address.city << " " << address.stateInitials
		<< " " << address.zipCode << endl << "Gender: " << gender << endl << "Interests: " << getInterest1() << " " << getInterest2()
		<< endl << endl;
}
void membershipType::print_member_type() {
	cout << personNum << ". " << firstName << " " << lastName << endl;
	cout << "Personal ID: " << personID << endl;
	cout << "Membership Status: " << membership_status << endl;
	cout << "Membership Type: " << membership_type << endl;
	cout << "Interests: " << getInterest1() << ", " << getInterest2() << endl;
	cout << address.streetAddressNum << " " << address.streetName
		<< " " << address.streetType << " " << address.city << " " << address.stateInitials
		<< " " << address.zipCode << endl << endl;
}
addressType::addressType() {
	streetAddressNum = -1;
	zipCode = -1;
	streetName = "";
	streetType = "";
	stateInitials = "";
	city = "";
	return;
}
personType::personType() {
	lastName = "";
	firstName = "";
	personID = -1;
	personNum = -1;
	gender = 'g';
	return;
}
membershipType::membershipType() {
	membership_status = ' ';
	membership_type = ' ';
}
membershipType::membershipType(char status, char type) {
	membership_status = status;
	membership_type = type;
}