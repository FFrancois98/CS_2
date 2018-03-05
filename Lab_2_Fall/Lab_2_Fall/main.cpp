#include <iostream>
#include <fstream>
#include "personType.h"
#include <string>
using namespace std;
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