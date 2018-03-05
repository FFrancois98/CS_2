#include <iostream>
#include <string>
#include "customer.h"
using namespace std;

queueType::queueType() {
	qfront = NULL;
	qrear = NULL;
}
queueType::~queueType() {
	nodeType* temp;
	while (qfront != NULL) {
		temp = qfront->next;
		delete qfront;
		qfront = temp;
	}
}
void queueType::printlist() {
	nodeType* temp = qfront;
	while (temp != NULL) {
		cout << temp->info.name << '\n';
		temp = temp->next;
	}
}
void queueType::enqueue(nodeType cus) {
	nodeType* csto = new nodeType;
	csto->info = cus.info;
	csto->next = NULL;
	if (qfront == NULL) {
		qfront = csto;
		qrear = csto;
	}
	else {
		qrear->next = csto;
		qrear = csto;
		qrear->next = NULL;
		return;
	}
}
nodeType queueType::dequeue() {
	nodeType* tempPtr = NULL;
	nodeType tempCus;
	if (qfront == NULL) {
		cout << "Empty Queue" << endl;
	}
	else {
		tempPtr = qfront;
		tempCus.info = tempPtr->info;
		qfront = qfront->next;
		delete tempPtr;
		return tempCus;
	}
}


