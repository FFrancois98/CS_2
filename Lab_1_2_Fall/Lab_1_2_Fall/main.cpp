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

int main()
{
	personType members[6];
	string x, i1, i2;
	ifstream myfile;
	myfile.open("infile.txt");
	for (int i = 0; i < 6; i++)
	{
		myfile >> members[i].lastName >> members[i].firstName >> members[i].personNum
			>> members[i].personID >> members[i].address.streetAddressNum >>
			members[i].address.streetName >> members[i].address.streetType
			>> members[i].address.city >> members[i].address.stateInitials
			>> members[i].address.zipCode >> members[i].gender;
		myfile >> i1 >> i2;
		members[i].setInterest1(i1);
		members[i].setInterest2(i2);
		members[i].printPerson();
	}
	myfile.close();
	system("pause");
	return 0;
}
/*
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