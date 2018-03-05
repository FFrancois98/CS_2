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
	SEARCH ComparedTo(nodeType*, nodeType);
	nodeType GetItem(nodeType, bool&);
	int length;
};

bool BinarySearch(sortedListType&, nodeType, nodeType*, nodeType*);

// ********************************************DRIVER*******************************************
int main() {
	sortedListType studentList;
	studentType student;
	nodeType* tester, *tester1, *tester2, *tempPtr, *fromLoc, *toLoc;
	bool found = true;
	int lgth = 0;
	ifstream myfile;
	myfile.open("infile2.txt");

	// creates the doubly linked list
	myfile >> student.fname;
	while (myfile) {
		myfile >> student.lname >> student.teamId >> student.city;
		studentList.insertInOrder(student);
		myfile >> student.fname;
	}
	cout << "THE STUDENT LIST" << endl;
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

	// testing the binary search function

	toLoc = studentList.head;
	while (toLoc->next != NULL) {
		toLoc = toLoc->next;
	}
	fromLoc = studentList.head;

	char continSearch = ' ';
	nodeType getStu; 
	while (continSearch != 'N') {						// User input testing binary search function
		cout << "Enter a first name, last name, team ID, and city to search: ";
		cin >> getStu.info.fname >> getStu.info.lname >> getStu.info.teamId >> getStu.info.city;

		cout << endl << "BINARY SEARCH FUNCTION FOR: " << getStu.info.fname << endl;
		found = BinarySearch(studentList, getStu, fromLoc, toLoc);

		if (found == true) {
			cout << endl << "Found is true and " << getStu.info.fname << " is found in the list." << endl;
		}
		else {
			cout << endl << "Found is false and " << getStu.info.fname << " is not in the list." << endl;
		}

		cout << endl << "Would you like to continue searching? (Y/N): ";
		cin >> continSearch;
	}

	myfile.close();
	system("pause");
	return 0;
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

SEARCH sortedListType::ComparedTo(nodeType* stuMidPoint, nodeType stuCompare) {
	// THE COMPARE MIDPOINT FUNCTION
	SEARCH result; // creates an enum variable
				   // if the node being searched is less than the midpoint node, return enum value LESS
	if (stuCompare.info.fname < stuMidPoint->info.fname) {
		result = LESS;
		return result;
	}// if the node being searched is greater than the midpoint node, return enum value GREATER
	else if (stuCompare.info.fname > stuMidPoint->info.fname) {
		result = GREATER;
		return result;
	}// if the node being searched is equal to midpoint node, return enum value EQUAL
	else {
		result = EQUAL;
		return result;
	}
}

bool BinarySearch(sortedListType& myList, nodeType stuCompare, nodeType* fromLocation, nodeType* toLocation) {
	// the list type has to be passed by reference to avoid memory errors with deletion
	// Binary Search Function 
	int lgth = 0;														// variable to calculate the distance between each node
	int mid = 0;														// variable to store the midpoint integer
	nodeType* midPoint;													// nodetype pointer for the midpoint
	nodeType* temp;														// nodetype pointer to find the length
	if (toLocation->info.fname >= fromLocation->info.fname) {			// if statement that exist while there is still more to search
		temp = fromLocation;
		while (temp->info.fname != toLocation->info.fname) {			// calcualtes the length between the nodes
			lgth++;
			temp = temp->next;
		}

		mid = lgth / 2;													// calculates the midpoint integer
		midPoint = fromLocation;
		for (int i = 0; i < mid - 1; i++) {								// finds the midpoint node
			midPoint = midPoint->next;
		}
		 // compares the mid point node to the search node and returns the value if equal
		if (myList.ComparedTo(midPoint, stuCompare) == EQUAL) {			
			return true;
		}// compares the mid point node to the search node and returns the value if less
		else if (myList.ComparedTo(midPoint, stuCompare) == LESS) {
			return BinarySearch(myList, stuCompare, fromLocation, midPoint->prev);
		}// compares the mid point node to the search node and returns the value if greater
		else {
			return BinarySearch(myList, stuCompare, midPoint->next, toLocation);
		}

	}
	return false;														// returns false when the name not found 
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
Enter a first name, last name, team ID, and city to search: Matthew Jacobs 8 Nashville

BINARY SEARCH FUNCTION FOR: Matthew

Found is true and Matthew is found in the list.

Would you like to continue searching? (Y/N): N
Press any key to continue . . .
Press any key to continue . . .
*/

