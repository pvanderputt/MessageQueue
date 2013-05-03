#include "MessageQueue.h"



MessageQueue::MessageQueue(void){
}

MessageQueue::~MessageQueue(void){
	ClearQueue();
}

void MessageQueue::AddMessage(Message* m){
	q.push(m);
}

Message* MessageQueue::GetFront(){
	if(q.size() == 0)
		return;

	return q.top();
}

Message* MessageQueue::TakeFront(){
	if(q.size() == 0)
		return;

	Message* temp = q.top();
	q.pop();
	return temp;
}

void MessageQueue::RemoveFront(){
	if(q.size() == 0)
		return;

	Message* temp = q.top();
	q.pop();
	delete temp;
}

void MessageQueue::ClearQueue(){
	while(q.size != 0){
		RemoveFront();
	}
}