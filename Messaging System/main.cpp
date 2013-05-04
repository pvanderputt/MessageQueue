#pragma once

#include "PostOffice.h"
#include <iostream>

using namespace std;



void main(){
	std::priority_queue<Message*, vector<Message*>, MessageComparison> testQ;
	MessageQueue testQ2;

	Message* m = new Message();
	m->timeToDelivery = 50;

	Message* n = new Message();
	n->timeToDelivery = 25;

	Message* o = new Message();
	o->timeToDelivery = 10;

	Message* p = new Message();
	p->timeToDelivery = 100;

	testQ2.AddMessage(p);

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	testQ2.AddMessage(m);

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	testQ2.AddMessage(n);

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	testQ2.AddMessage(o);

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	cout << "--------now to pop----------" << endl;
	testQ2.RemoveFront();

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	testQ2.RemoveFront();

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	testQ2.RemoveFront();

	cout << "top of testQ is: " << testQ2.GetFront()->timeToDelivery << endl;

	system("pause");

};