#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

void print(vector<membershipType>, vector<membershipType>::iterator);

int main()
{
	vector<membershipType> members;
	membershipType tempMembers;
	vector<membershipType>::iterator i;
	string x, i1, i2;
	ifstream myfile;
	myfile.open("infile.txt");
	cout << "Output: " << endl;
	for (int j = 0; j < 6; j++)
	{
		myfile >> tempMembers.lastName >> tempMembers.firstName >> tempMembers.personNum
			>> tempMembers.personID >> tempMembers.address.streetAddressNum >>
			tempMembers.address.streetName >> tempMembers.address.streetType
			>> tempMembers.address.city >> tempMembers.address.stateInitials
			>> tempMembers.address.zipCode >> tempMembers.gender;
		myfile >> i1 >> i2 >> tempMembers.membership_type >> tempMembers.membership_status;
		tempMembers.setInterest1(i1);
		tempMembers.setInterest2(i2);
		members.push_back(tempMembers);

		//tempMembers.print_member_type();
	}
	print(members, i);
	myfile.close();
	system("pause");
	return 0;
}

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

void print(vector<membershipType> members, vector<membershipType>::iterator i) {
	for (i = members.begin(); i != members.end(); ++i) {
		cout << "Person Number: " << (*i).personNum << endl << "Name: " << (*i).lastName << " " << (*i).firstName << endl
			<< "ID: " << (*i).personID << endl << "Address: " << (*i).address.streetAddressNum << " " << (*i).address.streetName
			<< " " << (*i).address.streetType << " " << (*i).address.city << " " << (*i).address.stateInitials
			<< " " << (*i).address.zipCode << endl << "Gender: " << (*i).gender << endl << "Interests: " << (*i).getInterest1() << " " << (*i).getInterest2()
			<< endl << endl;
	}
}
/*
Output:
Person Number: 1
Name: Herold, Jill
ID: 2234
Address: 123 Main St. Washington, DC 20019
Gender: F
Interests: yoga facebook

Person Number: 2
Name: Jackson, Stan
ID: 3748
Address: 12 Douglas Ave. Baltimore, MD 30229
Gender: M
Interests: sports movies

Person Number: 3
Name: Jerry, Francis
ID: 6666
Address: 2345 6th Street Woodbridge, VA 44040
Gender: M
Interests: movies roadtrips

Person Number: 4
Name: Joan, Wilson
ID: 1234
Address: 12 Georgia Ave. Washington, DC 20019
Gender: F
Interests: romance dining

Person Number: 5
Name: Smith, Stanley
ID: 3456
Address: 56 D Street Baltimore, MD 30229
Gender: M
Interests: movies dining

Person Number: 6
Name: Claire, Claude
ID: 2311
Address: 66 32nd Street Woodbridge, VA 44040
Gender: F
Interests: cooking facebook

Press any key to continue . . .
*/