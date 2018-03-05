#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Address_type
{
	int street_no;
	string street_name;
	string city;
	string state;
	int zip;
};
struct student_type
{
	string lname;
	string fname;
	int ID;
	float GPA;
	char classification;
	float account_balance;
	Address_type student_address;
};

void print_students(student_type[5]); // prototype

int main()
{
	ifstream myfile;
	myfile.open("infile.txt");
	student_type students[5];
	// Reads in the input data in the stuct
	for (int i = 0; i < 5; i++)
	{
		myfile >> students[i].lname >> students[i].fname >> students[i].ID
			>> students[i].GPA >> students[i].classification >> students[i].account_balance
			>> students[i].student_address.street_no;
		myfile.ignore(100, '\n');
		getline(myfile, students[i].student_address.street_name);
		myfile >> students[i].student_address.city >> students[i].student_address.state
			>> students[i].student_address.zip;
	}
	print_students(students);

}
// function that print the input data in to a table
void print_students(student_type students[])
{
	cout << "Student Name" << '\t' << "ID" << '\t' << "GPA" << '\t' << "Class"
		<< '\t' << "Balance" << '\t' << "Student Address" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << left << students[i].lname << ", " << students[i].fname << '\t' << students[i].ID;
		cout << left << '\t' << students[i].GPA << '\t' << students[i].classification << '\t' << fixed << showpoint <<
			setprecision(2) << students[i].account_balance;
		cout << left << '\t' << students[i].student_address.street_no << " " << students[i].student_address.street_name
			<< " " << students[i].student_address.city << " " << students[i].student_address.state << " " <<
			students[i].student_address.zip << endl;
	}
}
/*
Student Name    ID      GPA     Class   Balance Student Address
Smith, John     123456  3.4     J       1750.40 302 Fairmont St NW Washington DC 20059
Smitty, Frank   78910   2.70    F       1940.70 712 Sixth St SW Washington DC 20059
Mitty, Grank    75910   3.70    S       1990.70 375 Seventh St SW Washington DC 20059
Johnson, Garry  12756   3.80    S       150.40  456 Fairmont St NW Washington DC 20059
Brwn, Mike      56009   2.40    F       10.40   789 Fairmouth St NW Washington DC 20059
Press any key to continue . . .
*/