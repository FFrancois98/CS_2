#include <iostream>
#include <fstream>
#include "train.h"
using namespace std;

void main()
{
	TRAIN MetroLiner, MetLine2;
	MetroLiner.loadTrain();
	//MetroLiner.displayTrainInfo();
	MetLine2 = MetroLiner;
	if (&MetLine2 != &MetroLiner) {
		cout << "Assignment overload work" << endl;
	}
	else {
		cout << " Assigment didn't work" << endl;
	}
	//MetLine2.displayTrainInfo();s
	cout << "PROGRAM OUTPUT:" << endl;
	TRAIN MetLine3(MetroLiner);
	if (&MetLine3 != &MetroLiner) {
		cout << "Copy Construct worked" << endl;
	}
	else {
		cout << "Copy Construct didn't worked" << endl;
	}
	//MetroLiner.displayTrainInfo();
	system("pause");
	return;
}
