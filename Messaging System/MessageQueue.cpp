#include "MessageQueue.h"



MessageQueue::MessageQueue(){
}

MessageQueue::~MessageQueue(){
	ClearQueue();
}

void MessageQueue::AddMessage(Message* m){
	q.push(m);
}

Message* MessageQueue::GetFront(){
	return q.top();
}

Message* MessageQueue::TakeFront(){
	Message* temp = q.top();
	q.pop();
	return temp;
}

void MessageQueue::RemoveFront(){
	if(q.empty())
		return;

	Message* temp = q.top();
	q.pop();
	delete temp;
}

void MessageQueue::ClearQueue(){
	while(!q.empty()){
		RemoveFront();
	}
}

void MessageQueue::SubtractTime(float dt){
	for(auto &m : q.c){
		m->timeToDelivery -= dt;
	}
}

unsigned int MessageQueue::GetSize(){
	return q.size();
}

bool MessageQueue::IsEmpty(){
	return q.empty();
}