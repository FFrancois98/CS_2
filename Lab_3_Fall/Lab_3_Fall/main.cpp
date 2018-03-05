#include <iostream>
#include <fstream>
#include "personType.h"
#include <string>
#include <vector>
using namespace std;

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
void print(vector<membershipType> members, vector<membershipType>::iterator i) {
	for (i = members.begin(); i != members.end(); ++i) {
		cout << "Person Number: " << (*i).personNum << endl << "Name: " << (*i).lastName << " " << (*i).firstName << endl
			<< "ID: " << (*i).personID << endl << "Address: " << (*i).address.streetAddressNum << " " << (*i).address.streetName
			<< " " << (*i).address.streetType << " " << (*i).address.city << " " << (*i).address.stateInitials
			<< " " << (*i).address.zipCode << endl << "Gender: " << (*i).gender << endl << "Interests: " << (*i).getInterest1() << " " << (*i).getInterest2()
			<< endl << endl;
	}
}
