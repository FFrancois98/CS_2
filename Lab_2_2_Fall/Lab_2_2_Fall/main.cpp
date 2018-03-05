#include <iostream>
#include <fstream>
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

int main()
{
	membershipType members[6];
	string x, i1, i2;
	ifstream myfile;
	myfile.open("infile.txt");
	cout << "Output: " << endl;
	for (int i = 0; i < 6; i++)
	{
		myfile >> members[i].lastName >> members[i].firstName >> members[i].personNum
			>> members[i].personID >> members[i].address.streetAddressNum >>
			members[i].address.streetName >> members[i].address.streetType
			>> members[i].address.city >> members[i].address.stateInitials
			>> members[i].address.zipCode >> members[i].gender;
		myfile >> i1 >> i2 >> members[i].membership_type >> members[i].membership_status;
		members[i].setInterest1(i1);
		members[i].setInterest2(i2);
		members[i].print_member_type();
	}
	myfile.close();
	system("pause");
	return 0;
}
/*
Output:
1. Jill Herold,
Personal ID: 2234
Membership Status: 2
Membership Type: 1
Interests: yoga, facebook
123 Main St. Washington, DC 20019

2. Stan Jackson,
Personal ID: 3748
Membership Status: 4
Membership Type: 2
Interests: sports, movies
12 Douglas Ave. Baltimore, MD 30229

3. Francis Jerry,
Personal ID: 6666
Membership Status: 1
Membership Type: 1
Interests: movies, roadtrips
2345 6th Street Woodbridge, VA 44040

4. Wilson Joan,
Personal ID: 1234
Membership Status: 3
Membership Type: 2
Interests: romance, dining
12 Georgia Ave. Washington, DC 20019

5. Stanley Smith,
Personal ID: 3456
Membership Status: 1
Membership Type: 2
Interests: movies, dining
56 D Street Baltimore, MD 30229

6. Claude Claire,
Personal ID: 2311
Membership Status: 1
Membership Type: 1
Interests: cooking, facebook
66 32nd Street Woodbridge, VA 44040

Press any key to continue . . .
*/