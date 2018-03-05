#include <iostream>
#include "train.h"
using namespace std;

TRAIN::TRAIN()
{
	trainWeight = 0;
	firstCar = NULL;
}
int TRAIN::getWeight() // returns the train weight
{
	return trainWeight;
}
void TRAIN::loadTrain() // load train with initial cars
{
	addCar_front(0); // add first car       
	addCar_front(10);
	addCar_front(20);
	addCar_front(30);
	addCar_front(40);
	addCar_front(50);
	addCar_front(60);
	addCar_end(60);
	addCar_end(30);
	addCar_end(40);
}
CAR::CAR()
{
	cargoWeight = 0;
	nextCar = nullptr;
}
int CAR::getWeight()
{
	return cargoWeight;
}
void CAR::loadCar(int cargo)
{
	cargoWeight = cargo;
}
void TRAIN::addCar_end(int cWeight)    // add car to end    
{
	// YOU MUST WRITE THIS FUNCTION
	CAR* end = new CAR();
	end->loadCar(cWeight);
	end->nextCar = NULL;

	if (firstCar == NULL) {
		firstCar = end;
	}
	else {
		CAR* temp = firstCar;
		while (temp->nextCar != NULL) {
			temp = temp->nextCar;
		}
		temp->nextCar = end;
	}
}
void TRAIN::addCar_front(int cWeight)  // add first car to train                                                   
{
	// YOU MUST WRITE THIS FUNCTION
	CAR* front = new CAR();
	front->loadCar(cWeight);
	front->nextCar = firstCar;
	firstCar = front;
	return;
}
TRAIN::~TRAIN() {
	CAR* temp;
	while (firstCar != NULL) {
		temp = firstCar->nextCar;
		delete firstCar;
		firstCar = temp;
		displayTrainInfo();
	}
	cout << "Destructor was called" << endl;
}
void TRAIN::displayTrainInfo()
{
	int cnt = 0;
	CAR* ptrCar;
	for (ptrCar = firstCar; ptrCar != NULL && ++cnt <11; ptrCar = ptrCar->nextCar)
		cout << "+-------+  ";
	cout << endl;
	cnt = 0;
	for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
		cout << "|       |  ";
	cout << endl; cnt = 0;
	for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
	{
		if ((*ptrCar).getWeight() < 10)
			cout << "|   " << (*ptrCar).getWeight() << "   |->";  else    cout << "|   " <<
			(*ptrCar).getWeight() << "  |->";
	}
	cout << endl; cnt = 0;
	for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
		cout << "|       |  ";
	cout << endl;
	cnt = 0;
	for (ptrCar = firstCar; ptrCar != NULL && ++cnt < 11; ptrCar = ptrCar->nextCar)
		cout << "+-------+  ";
	cout << endl;
}
