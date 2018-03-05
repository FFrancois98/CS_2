#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class contactType {
public:  // declare public variables and functions
	string fname;
	string lname;
	string phoneNum;
};
class nodeType {
public:
	contactType info;
	nodeType* next;
};
class sortedListType {
public:
	void insertInOrder(contactType);
	void printList();
	sortedListType();
	~sortedListType();
	nodeType* head;
};

void listMerge(sortedListType&, sortedListType&, sortedListType&);

int main() {
	sortedListType customer1List;
	sortedListType customer2List;
	sortedListType combinedList;
	contactType contact;
	ifstream myfile;
	myfile.open("infile.txt");
	int i;
	for (i = 0; i < 7; i++) {
		myfile >> contact.fname >> contact.lname >> contact.phoneNum;
		customer1List.insertInOrder(contact);
	}
	for (i = 0; i < 7; i++) {
		myfile >> contact.fname >> contact.lname >> contact.phoneNum;
		customer2List.insertInOrder(contact);
	}
	cout << endl <<  "\t\tCustomer 1 Contact List" << endl << endl;
	customer1List.printList();
	cout << endl <<  "\t\tCustomer 2 Contact List" << endl << endl;
	customer2List.printList();
	listMerge(customer1List, customer2List, combinedList);
	cout << endl <<  "\t\tCombined Contact List" << endl << endl;
	combinedList.printList();
	myfile.close();

}

sortedListType::sortedListType() { // constructor
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
void sortedListType::printList() { // print out list
	nodeType* temp = head;
	while (temp != NULL) {
		cout <<  temp->info.fname << setw(5) << '\t' << temp->info.lname << setw(5) << '\t'
			<< temp->info.phoneNum << endl;
		temp = temp->next;
	}
}
void sortedListType::insertInOrder(contactType stu) { // insert function
	nodeType* contact = new nodeType;
	contact->info = stu;
	contact->next = NULL;
	nodeType* tempPtr = NULL;
	nodeType* prevPtr = NULL;
	if (head == NULL) { // List empty
		head = contact;
	}
	else { // travese the list 
		for (tempPtr = head; tempPtr != NULL; prevPtr = tempPtr, tempPtr = tempPtr->next) {
			if ((contact->info.lname <= tempPtr->info.lname) && head == tempPtr) { // insert front
				contact->next = head;
				head = contact;
				return;
			}
			else if (contact->info.lname <= tempPtr->info.lname) { // insert between
				contact->next = tempPtr;
				prevPtr->next = contact;
				return;
			}
			else if (tempPtr->next == NULL) { // insert end
				tempPtr->next = contact;
				return;
			}
		}
	}
}
void listMerge(sortedListType& cus1, sortedListType& cus2, sortedListType& comb) {
	nodeType* tempPtr1 = NULL;
	nodeType* tempPtr2 = NULL;
	contactType contact;
	contactType contact2;
	for (tempPtr1 = cus1.head, tempPtr2 = cus2.head; tempPtr1 != NULL; tempPtr1 = tempPtr1->next, tempPtr2 = tempPtr2->next) {
		contact = tempPtr1->info;
		contact2 = tempPtr2->info;
		comb.insertInOrder(contact);
		comb.insertInOrder(contact2);
	}
}
/*


Customer 1 Contact List

Adegboyega      Akinsiku        (202)234-5678
Jonnetta        Bratcher        (345)444-6738
Dhuel           Fisher          (410)878-5503
Remington       Holt            (310)567-2349
Kendall         Keeling         (202)694-0090
Joanna          Phillip         (304)550-1236
Ranjay          Salmon          (410)555-6666

Customer 2 Contact List

Charles         Brown           (201)223-0021
Kerisha         Burke           (310)445-2939
Allee           Clark           (410)778-3848
Brionna         Huskey          (921)858-2348
Brittany        Jackson         (410)120-4502
Kourtnei        Langley         (202)880-6729
Michael         Phillips        (404)567-2345

Combined Contact List

Adegboyega      Akinsiku        (202)234-5678
Jonnetta        Bratcher        (345)444-6738
Charles         Brown           (201)223-0021
Kerisha         Burke           (310)445-2939
Allee           Clark           (410)778-3848
Dhuel           Fisher          (410)878-5503
Remington       Holt            (310)567-2349
Brionna         Huskey          (921)858-2348
Brittany        Jackson         (410)120-4502
Kendall         Keeling         (202)694-0090
Kourtnei        Langley         (202)880-6729
Joanna          Phillip         (304)550-1236
Michael         Phillips        (404)567-2345
Ranjay          Salmon          (410)555-6666
Press any key to continue . . .

*/