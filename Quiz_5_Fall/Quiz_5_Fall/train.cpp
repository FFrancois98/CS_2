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
	insert(0); // add first car       
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	insert(60);
	insert(30);
	insert(40);
}
CAR::CAR()
{
	cargoWeight = 0;
	nextCar = NULL;
}
int CAR::getWeight()
{
	return cargoWeight;
}
void CAR::loadCar(int cargo)
{
	cargoWeight = cargo;
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
void TRAIN::insert(int cWeight) {   // add the car anywhere to train
	CAR* mainCar = new CAR();
	mainCar->loadCar(cWeight);
	mainCar->nextCar = NULL;
	CAR* tempPtr = 0;
	CAR* prevPtr = 0;
	if (firstCar == NULL) { // List empty
		firstCar = mainCar;
	}
	else {
		for (tempPtr = firstCar; tempPtr != NULL; prevPtr = tempPtr, tempPtr = tempPtr->nextCar) {
			if (mainCar->getWeight() <= tempPtr->getWeight() && firstCar == tempPtr) {
				mainCar->nextCar = firstCar;
				firstCar = mainCar;
				return;
			}
			else if (mainCar->getWeight() <= tempPtr->getWeight()) {
				mainCar->nextCar = tempPtr;
				prevPtr->nextCar = mainCar;
				return;
			}
			else if (tempPtr->nextCar == NULL) {
				tempPtr->nextCar = mainCar;
				return;
			}
		}
	}
}

TRAIN::~TRAIN() {
	CAR* temp;
	while (firstCar != NULL) {
		temp = firstCar->nextCar;
		delete firstCar;
		firstCar = temp;
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
const TRAIN& TRAIN::operator=(const TRAIN& RHS)
{
	this->~TRAIN();
	CAR* current = RHS.firstCar;
	CAR* currentLHS = new CAR;
	currentLHS->loadCar(current->getWeight());
	currentLHS->nextCar = NULL;
	this->firstCar = currentLHS;
	for (current = RHS.firstCar->nextCar; current != NULL; current = current->nextCar)
	{
		//currentLHS->nextCar = new CAR;
		//currentLHS->nextCar->loadCar(current->getWeight());
		//currentLHS->nextCar = NULL;
		this->addCar_end(current->getWeight());
	}
	return *this;
}
TRAIN::TRAIN(const TRAIN& LHS)
{ 
	firstCar = new CAR;
	CAR* currentLHS = LHS.firstCar;
	CAR* current = firstCar;
	firstCar->loadCar(LHS.firstCar->getWeight());// 
	current->nextCar = new CAR;
	currentLHS = currentLHS->nextCar;
	for (current = firstCar->nextCar; currentLHS->nextCar != NULL; currentLHS = currentLHS->nextCar)
	{
		current->loadCar(currentLHS->getWeight());
		current->nextCar = new CAR;
		current = current->nextCar;
	}
	current->loadCar(currentLHS->getWeight());
	current->nextCar = NULL;
}