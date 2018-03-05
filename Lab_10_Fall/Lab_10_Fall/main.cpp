#include <iostream>
#include <fstream>
#include <string>
#include "customer.h"
using namespace std;

int main() {
	queueType customerLine;
	nodeType custo;
	string addy, streetNum, streetName, streetType, city;
	string state, zip, lastName, firstName, names;
	ifstream myfile;
	myfile.open("infile.txt");
	myfile >> lastName;
	while (myfile) {
		myfile >> firstName >> custo.info.id >> streetNum >> streetName >> streetType >> city >> state >> zip
			>> custo.info.gender;
		addy = streetNum + " " + streetName + " " + streetType + " " + city + " " + state + " " + zip;
		names = lastName + " " + firstName;
		custo.info.address = addy;
		custo.info.name = names;
		customerLine.enqueue(custo);
		myfile >> lastName;
	}
	for (int i = 0; i < 3; i++) {
		customerLine.dequeue();
	}
	customerLine.printlist();
	return 0;
}

