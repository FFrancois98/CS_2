#include <iostream>
#include <fstream>
#include "personType.h"
#include <string>
using namespace std;

void print(nodeType*);

int main()
{
	membershipType tempMembers[6];
	string i1, i2;
	ifstream myfile;
	myfile.open("infile.txt");
	cout << "Output: " << endl;
	for (int j = 0; j < 6; j++)
	{
		myfile >> tempMembers[j].lastName >> tempMembers[j].firstName >> tempMembers[j].personNum
			>> tempMembers[j].personID >> tempMembers[j].address.streetAddressNum >>
			tempMembers[j].address.streetName >> tempMembers[j].address.streetType
			>> tempMembers[j].address.city >> tempMembers[j].address.stateInitials
			>> tempMembers[j].address.zipCode >> tempMembers[j].gender;
		myfile >> i1 >> i2 >> tempMembers[j].membership_type >> tempMembers[j].membership_status;
		tempMembers[j].setInterest1(i1);
		tempMembers[j].setInterest2(i2);
	}

	nodeType* headNode;
	headNode = new nodeType;
	headNode->mbr = tempMembers[0];
	headNode->nextPtr = new nodeType;
	print(headNode);

	nodeType* currNode;
	int nodeIterate = 1;
	for (currNode = headNode; nodeIterate < 6; currNode->nextPtr = new nodeType) {
		currNode->nextPtr->mbr = tempMembers[nodeIterate];
		nodeIterate++;
		currNode = currNode->nextPtr;
		print(currNode);
	}
	currNode->nextPtr = nullptr;

	myfile.close();
	system("pause");
	return 0;
}
void print(nodeType* members) {
	cout << "Person Number: " << members->mbr.personNum << endl << "Name: " 
		<< members->mbr.lastName << " " << members->mbr.firstName << endl 
		<< "ID: " << members->mbr.personID << endl << "Address: " 
		<< members->mbr.address.streetAddressNum << " " << members->mbr.address.streetName 
		<< " " << members->mbr.address.streetType << " " << members->mbr.address.city 
		<< " " << members->mbr.address.stateInitials << " "	<< members->mbr.address.zipCode 
		<< endl << "Gender: " << members->mbr.gender << endl << "Interests: " 
		<< members->mbr.getInterest1() << ", " << members->mbr.getInterest2() << endl << endl;
}
/*
Output:
Person Number: 1
Name: Herold, Jill
ID: 2234
Address: 123 Main St. Washington, DC 20019
Gender: F
Interests: yoga, facebook

Person Number: 2
Name: Jackson, Stan
ID: 3748
Address: 12 Douglas Ave. Baltimore, MD 30229
Gender: M
Interests: sports, movies

Person Number: 3
Name: Jerry, Francis
ID: 6666
Address: 2345 6th Street Woodbridge, VA 44040
Gender: M
Interests: movies, roadtrips

Person Number: 4
Name: Joan, Wilson
ID: 1234
Address: 12 Georgia Ave. Washington, DC 20019
Gender: F
Interests: romance, dining

Person Number: 5
Name: Smith, Stanley
ID: 3456
Address: 56 D Street Baltimore, MD 30229
Gender: M
Interests: movies, dining

Person Number: 6
Name: Claire, Claude
ID: 2311
Address: 66 32nd Street Woodbridge, VA 44040
Gender: F
Interests: cooking, facebook

Press any key to continue . . .
*/