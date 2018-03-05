#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//******************************************* SPECFICATION***************************************
enum SEARCH { LESS, GREATER, EQUAL };

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
	nodeType* prev;
};
class sortedListType {
public:
	void insertInOrder(studentType);
	void printList();
	sortedListType();
	~sortedListType();
	nodeType* head;
	nodeType* gotoNode(nodeType*, int, char);
	SEARCH ComparedTo(int, nodeType);
	nodeType GetItem(nodeType, bool&);
	int length;
};

// ********************************************DRIVER*******************************************
int main() {
	sortedListType studentList;
	studentType student;
	nodeType* tester, *tester1, *tester2, *tempPtr;
	bool found = true;
	ifstream myfile;
	myfile.open("infile.txt");

	// creates the doubly linked list
	myfile >> student.fname;
	while (myfile) {
		myfile >> student.lname >> student.teamId >> student.city;
		studentList.insertInOrder(student);
		myfile >> student.fname;
	}
	cout << "THE STUDENT LIST IN FIRST NAME ALPHABETICAL ORDER" << endl;
	studentList.printList();

	cout << endl << "TESTING THE FUNCTIONS" << endl;
	// test cases of gotoNode by print out the fname
	tester = studentList.gotoNode(studentList.head, 0, 'F'); // head test
	cout << endl << "The First Student Node using Forward: " << tester->info.fname << endl;
	tempPtr = NULL;
	tempPtr = studentList.head;

	// test the gotonode function
	cout << endl << "Testing the gotoNode Function" << endl;
	while (tempPtr->next != NULL) {
		if (tempPtr->info.teamId == 7) {
			cout << "The student with a Team ID of 7: " << tempPtr->info.fname << endl;
			tester1 = studentList.gotoNode(tempPtr, 3, 'F'); // 3 test cases
			cout << "The student 3 nodes forward: " << tester1->info.fname << endl;
		}
		tempPtr = tempPtr->next;
	}
	tester2 = studentList.gotoNode(tempPtr, 0, 'B'); // tail test
	cout << endl << "The Last Student Node using Backwards: " << tester2->info.fname << endl;

	// test the binary search function
	nodeType getStu;
	getStu.info.fname = "Matbthew";
	getStu.info.lname = "Jacobs";
	getStu.info.teamId = 8;
	getStu.info.city = "Nashville";
	studentList.GetItem(getStu, found);
	if (found == true) {
		cout << "Found is true and " << getStu.info.fname << " exists in the list" << endl;
	}
	else {
		cout << "Found is false and " << getStu.info.fname << " doesn't exist in the list" << endl;
	}

	getStu.info.fname = "Ranjay";
	getStu.info.lname = "Salmon";
	getStu.info.teamId = 2;
	getStu.info.city = "Trenton";
	studentList.GetItem(getStu, found);
	if (found == true) {
		cout << "Found is true and " << getStu.info.fname << " exists in the list" << endl;
	}
	else {
		cout << "Found is false and " << getStu.info.fname << " doesn't exist in the list" << endl;
	}

	myfile.close();
}

// ********************************IMPLEMENTATION******************************************
sortedListType::sortedListType() { // constructor
	length = 0;
	head = NULL;
}
sortedListType::~sortedListType() { // deconstructor
	nodeType* temp;
	while (head != NULL) {
		temp = head->next;
		delete head;
		head = temp;
	}
}
nodeType* sortedListType::gotoNode(nodeType* current, int moves, char direct) { // returns pointer
	nodeType* movement = NULL;
	movement = current;
	if (direct == 'F') {
		for (int i = 0; i < moves; i++) {
			movement = movement->next;
		}
	}
	else if (direct == 'B') {
		for (int i = 0; i < moves; i++) {
			movement = movement->prev;
		}
	}
	return movement;
}
void sortedListType::printList() { // print out list
	nodeType* temp = head;
	while (temp != NULL) {
		cout << temp->info.fname << " " << temp->info.lname << " "
			<< temp->info.teamId << " " << temp->info.city << endl;
		temp = temp->next;
	}
}
void sortedListType::insertInOrder(studentType stu) { // insert function
	nodeType* student = new nodeType;
	student->info = stu;
	student->next = NULL;
	student->prev = NULL;
	nodeType* tempPtr = NULL;
	nodeType* prevPtr = NULL;
	length++;
	if (head == NULL) { // List empty
		head = student;
	}
	else { // travese the list 
		for (tempPtr = head; tempPtr != NULL; prevPtr = tempPtr, tempPtr = tempPtr->next) {
			if (student->info.fname <= tempPtr->info.fname && head == tempPtr) { // insert front
				head->prev = student;
				student->next = head;
				head = student;
				return;
			}
			else if (student->info.fname <= tempPtr->info.fname) { // insert between
				student->next = tempPtr;
				student->prev = prevPtr;
				prevPtr->next = student;
				tempPtr->prev = student;
				return;
			}
			else if (tempPtr->next == NULL) { // insert end
				tempPtr->next = student;
				student->prev = tempPtr;
				return;
			}
		}
	}
}

SEARCH sortedListType::ComparedTo(int stuMidPoint, nodeType stuCompare) {
	// THE COMPARE MIDPOINT FUNCTION
	SEARCH result; // creates an enum variable
	nodeType* temp = head; // creates a temp pointer and sets it equal to the first head
	for (int i = 0; i < stuMidPoint - 1; i++) { // sets the temp pointer to the midpoint node
		temp = temp->next;
	}
	// if the node being searched is less than the midpoint node, return enum value LESS
	if (stuCompare.info.fname < temp->info.fname) {
		result = LESS;
		return result;
	}// if the node being searched is greater than the midpoint node, return enum value GREATER
	else if (stuCompare.info.fname > temp->info.fname) {
		result = GREATER;
		return result;
	}// if the node being searched is equal to midpoint node, return enum value EQUAL
	else {
		result = EQUAL;
		return result;
	}
}
nodeType sortedListType::GetItem(nodeType stuCompare, bool& found) {
	// THE BINARY SEARCH FUNCTION
	int first = 0; // sets the values of first, last, mid variables
	int mid = 0;
	int last = length - 1;
	found = false;
	bool moreToSearch = (first <= last); // checks to see if there is anything to search in the list
	cout << endl << "BINARY SEARCH STARTING FOR: " << stuCompare.info.fname << endl;

	while (moreToSearch && !found) { // while there are things to search and the object not found

		mid = (first + last) / 2; // find the midpoint integer value
		cout << "first " << first << endl; // display the values of first, last and midpoint
		cout << "last " << last << endl;
		cout << "mid " << mid << endl << endl;
		switch (ComparedTo(mid, stuCompare)) { // calls the ComparedTo function and returns its value
		case LESS: // if return value is LESS, value of last becomes one less than the midpoint
			last = mid - 1;
			moreToSearch = (first <= last);
			break;
		case GREATER: // if return value is GREATER, value of first becomes one greater than the midpoint
			first = mid + 1;
			moreToSearch = (first <= last);
			break;
		case EQUAL: // if return value is EQUAL, the student was found in the list and the bool found is set equal to true
			found = true;
			break;
		default:
			break;
		}

	}
	return stuCompare; // returns the student that was being searched
}
/*
THE STUDENT LIST
Adegboyega Akinsiku 4 Topeka
Aja Walton 3 Boise
Allee Clark 4 Pittsburg
Alyssa Bullock 6 Baltimore
Ashlee McKinney 3 Houston
Blanche Mahop 6 Austin
Brionna Huskey 1 Sacramento
Brittany Jackson 5 Denver
Candace Ross 0 Rockville
Charles Brown 0 Bowie
Cherith-Eden Clements 5 Hagerstown
Crepin Mahop 2 Bolder
Dhuel Fisher 8 Richmord
Illium Williams 8 Juray
Isa Edwards-El 3 Greensburg
Jaleesa Harrigan 1 Harrisonburg
Jennifer Ojie 7 Arlington
Joanna Phillip 1 Tampa
Johan Lingani 8 Woodbridge
Jonnetta Bratcher 3 Charleston
Kareem Parris-Baptiste 8 Princeton
Kendall Keeling 3 Miami
Kerisha Burke 7 Washington
Kourtnei Langley 9 Louisville
Kyle Ward 5 Germantown
Malcolm Williams 2 Winchester
Matthew Jacobs 8 Nashville
Michael Phillips 3 Boston
Ranjay Salmon 2 Trenton
Rashad Rose 7 Fredricksburg
Remington Holt 2 Detriot
Saboor Salaam 1 Reston
Susan Angus 3 Burke
Terrance Ellis 6 Columbia
Theodore Santos-Gaffney 9 Towson
Vor Foreman 4 Earlsville

TESTING THE FUNCTIONS

The First Student Node using Forward: Adegboyega

Testing the gotoNode Function
The student with a Team ID of 7: Jennifer
The student 3 nodes forward: Jonnetta
The student with a Team ID of 7: Kerisha
The student 3 nodes forward: Malcolm
The student with a Team ID of 7: Rashad
The student 3 nodes forward: Susan

The Last Student Node using Backwards: Vor

BINARY SEARCH STARTING FOR: Matbthew
first 0
last 35
mid 17

first 18
last 35
mid 26

first 27
last 35
mid 31

first 27
last 30
mid 28

first 27
last 27
mid 27

Found is false and Matbthew doesn't exist in the list

BINARY SEARCH STARTING FOR: Ranjay
first 0
last 35
mid 17

first 18
last 35
mid 26

first 27
last 35
mid 31

first 27
last 30
mid 28

first 29
last 30
mid 29

Found is true and Ranjay exists in the list

*/