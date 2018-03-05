#include <iostream>
#include <fstream>
#include "train.h"
using namespace std;

void main()
{
	TRAIN MetroLiner, MetLine2;
	MetroLiner.loadTrain();

	cout << "PROGRAM OUTPUT:" << endl;
	MetroLiner.displayTrainInfo();
	MetLine2 = MetroLiner;
	if (&MetLine2 != &MetroLiner) {
		cout << endl << "Lists are not pointing to the same address," << endl << "Assignment overload operator worked" << endl;
	}
	else {
		cout << " Assigment didn't work" << endl;
	}
	MetLine2.displayTrainInfo();

	TRAIN MetLine3(MetroLiner);
	if (&MetLine3 != &MetroLiner) {
		cout << endl << "Lists are not pointing to the same address," << endl << "Copy Constructor worked" << endl;
	}
	else {
		cout << "Copy Constructor didn't worked" << endl;
	}
	MetroLiner.displayTrainInfo();

	system("pause");
	return;
}
/*
PROGRAM OUTPUT:
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
|   0   |->|   10  |->|   20  |->|   30  |->|   30  |->|   40  |->|   40  |->|   50  |->|   60  |->|   60  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
Destructor was called

Lists are not pointing to the same address,
Assignment overload operator worked
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
|   0   |->|   10  |->|   20  |->|   30  |->|   30  |->|   40  |->|   40  |->|   50  |->|   60  |->|   60  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+

Lists are not pointing to the same address,
Copy Constructor worked
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
|   0   |->|   10  |->|   20  |->|   30  |->|   30  |->|   40  |->|   40  |->|   50  |->|   60  |->|   60  |->
|       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |  |       |
+-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+  +-------+
Press any key to continue . . .
Destructor was called
Destructor was called
Destructor was called
Press any key to continue . . .
*/