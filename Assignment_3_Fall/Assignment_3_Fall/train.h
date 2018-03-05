#pragma once
#include <string>
#include <fstream>
using namespace std;

class CAR                                       // class for train cars
{
public:
	CAR();                              // constructor       
	int getWeight();             // returns the weight of the car in pounds   
	void loadCar(int);           // loads a cargo with parameter weight      
	CAR *nextCar;                // pointer to the next car on the train
private:
	int cargoWeight;              // the weight of the trains cargo
};
class TRAIN                     // train class as a linked list of cars
{
public:
	TRAIN();                   //constructor       
	int getWeight();           // returns the weight of the train      
	void loadTrain();          // load train with initial cars      
	void addCar_front(CAR*);   // adds car to the front 
	void insert(int);			// adds the car anywhere to the train
	~TRAIN();                   // destructor THIS IS CODE YOU MUST WRITE
	const TRAIN& operator=(const TRAIN&);
	TRAIN(const TRAIN&);
	void displayTrainInfo();
	CAR *firstCar;
private:
	int trainWeight;
};

