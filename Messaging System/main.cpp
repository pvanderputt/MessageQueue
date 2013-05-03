#pragma once

#include "PostOffice.h"
#include <iostream>

using namespace std;



void main(){
	std::priority_queue<Message*, vector<Message*>, MessageComparison> testQ;

	Message* m = new Message();
	m->timeToDelivery = 100;

	Message* n = new Message();
	n->timeToDelivery = 10;

	Message* o = new Message();
	o->timeToDelivery = 20;

	Message* p = new Message();
	p->timeToDelivery = 50;

	testQ.push(p);

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	testQ.push(m);

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	testQ.push(n);

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	testQ.push(o);

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	cout << "--------now to pop----------" << endl;
	testQ.pop();

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	testQ.pop();

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	testQ.pop();

	cout << "top of testQ is: " << testQ.top()->timeToDelivery << endl;

	system("pause");

};