#include "MessageQueue.h"



MessageQueue::MessageQueue(){
}

MessageQueue::~MessageQueue(){
	ClearQueue();
}

void MessageQueue::AddMessage(Message* m){
	//q.push(m);
	//
	auto it = q.before_begin();
	for(auto x : q){
		if(x->timeToDelivery > m->timeToDelivery)
			break;
		++it;
	}
	q.insert_after(it, m);
	++qSize;
}

Message* MessageQueue::GetFront(){
	return q.front();
}

Message* MessageQueue::TakeFront(){
	--qSize;
	Message* temp = q.front();
	q.pop_front();
	return temp;
}

void MessageQueue::RemoveFront(){
	if(q.empty())
		return;

	--qSize;
	//Message* temp = q.top();
	//q.pop();
	//delete temp;
}

void MessageQueue::ClearQueue(){
	while(!q.empty()){
		RemoveFront();
	}
}

void MessageQueue::UpdateMessageTime(float dt){
	//for(auto &m : q.c){
	//	m->timeToDelivery -= dt;
	//}
}

int MessageQueue::GetSize(){
	return qSize;
}

bool MessageQueue::IsEmpty(){
	return q.empty();
}