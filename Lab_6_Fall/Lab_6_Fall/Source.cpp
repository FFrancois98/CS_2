#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class studentType {
public:  // declare public variables and functions
	string fname;
	string lname;
	int teamId;
	string city;
};
class nodeType {
public:
	studentType info;
	nodeType* next;
};
class unsortedListType {
public:
	void insertMid(studentType);
	void insertFront(studentType);
	void insertEnd(studentType);
	void printList();
	unsortedListType();
	~unsortedListType();
	nodeType* firstPtr;
};
int main() {
	unsortedListType studentList;
	studentType student;
	ifstream myfile;
	myfile.open("infile.txt");
	myfile >> student.fname;
	while (myfile) {
		myfile >> student.lname >> student.teamId >> student.city;
		if (student.teamId % 2 == 1) {
			studentList.insertFront(student);
		}
		else if (student.teamId % 2 == 0) {
			studentList.insertEnd(student);
		}
		myfile >> student.fname;
	}
	student.fname = "Harry"; student.lname = "Keeling";	student.teamId = 20;
	student.city = "Dallas";
	studentList.insertMid(student);
	studentList.printList();
	
}
unsortedListType::unsortedListType(){
	firstPtr = NULL;
}
unsortedListType::~unsortedListType() {
	nodeType* temp;
	while (firstPtr != NULL) {
		temp = firstPtr->next;
		delete firstPtr;
		firstPtr = temp;
	}
}
void unsortedListType::printList() {
	nodeType* temp = firstPtr;
	while (temp != NULL) {
		cout << temp->info.fname << " " << temp->info.lname << " " 
			<< temp->info.teamId << " " << temp->info.city << endl;
		temp = temp->next;
	}
}
void unsortedListType::insertMid(studentType stu) {
	nodeType* student = new nodeType;
	student->info = stu;
	student->next = NULL;
	nodeType* tempPtr = 0;
	nodeType* prevPtr = 0;
	nodeType* temp = firstPtr;
	
	for (tempPtr = firstPtr; tempPtr != NULL; prevPtr = tempPtr, tempPtr = tempPtr->next) {
		if ((tempPtr->info.teamId % 2 == 0) && (prevPtr->info.teamId % 2 == 1)) {
			student->next = tempPtr;
			prevPtr->next = student;
			return;
		}
	}
}
void unsortedListType::insertEnd(studentType stu) {
	nodeType* student = new nodeType;
	student->info = stu;
	student->next = NULL;
	if (firstPtr == NULL) { // List empty
		firstPtr = student;
	}
	else {
		nodeType* temp = firstPtr;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = student;
	}
}
void unsortedListType::insertFront(studentType stu) {
	nodeType* student = new nodeType;
	student->info = stu;
	student->next = NULL;
	nodeType* tempPtr = 0;
	nodeType* prevPtr = 0;
	if (firstPtr == NULL) { // List empty
		firstPtr = student;
	}
	else {
		student->next = firstPtr;
		firstPtr = student;
		return;
	}
}


