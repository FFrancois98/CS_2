#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//specification
class customerType
{
public:
	string name;
	int id;
	string address;
	char gender;
};

struct nodeType
{
	customerType info;
	nodeType* next;
};

class queueType
{
public:
	queueType();
	~queueType();
	void enqueue(nodeType); //add to end
	nodeType dequeue(); //remove from front
	void printlist();
private:
	nodeType* qfront;
	nodeType* qrear;
};