#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class studentType {
public:  // declare public variables and functions
	string name;
	char classification;
	string hometown;
	int id;
	float getGPA();
	void setGPA(float);
	void show_public_info();
private:
	float gpa; // declare private GPA
};
// set the value of the GPA
void studentType::setGPA(float orgGPA) {
	gpa = orgGPA;
	return;
}
// assess a private variable
float studentType::getGPA() {
	return gpa;
}
// displays the public variables
void studentType::show_public_info() {
	cout << name << endl;
	cout << classification << endl;
	cout << hometown << endl;
	cout << id << endl;
}
int main() {
	studentType you, me; // creates two objects of the studentType class
	you.name = "You"; // set values of public variables
	you.classification = 'F';
	you.hometown = "Brooklyn";
	you.id = 345;
	me.name = "Me";
	me.classification = 'S';
	me.hometown = "Crown Heights";
	me.id = 122;
	
	you.setGPA(2.75); // set values of the GPAs
	me.setGPA(3.95);
	// displays all of the values of each object
	you.show_public_info();
	cout << you.getGPA() << endl << endl;
	me.show_public_info();
	cout << me.getGPA() << endl;
}
/*
You
F
Brooklyn
345
2.75

Me
S
Crown Heights
122
3.95
Press any key to continue . . .
*/