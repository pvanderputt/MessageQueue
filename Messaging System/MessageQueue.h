#pragma once

#include "Message.h"
//#include <queue>
#include <list>
#include <forward_list>


//the MessageQueue class acts as a wrapper for the priority queue

class MessageQueue{
private:
	//std::priority_queue<Message*, std::vector<Message*>, MessageComparison> q;
	std::forward_list<Message*> q;
	int qSize;

public:
	MessageQueue();
	~MessageQueue();

	//adds a message to the queue
	void AddMessage(Message* m);

	//returns a pointer to the top message in the queue
	Message* GetFront();

	//returns a pointer to the top message in the queue and removes the message from the queue
	Message* TakeFront();

	//deletes the top message in the queue
	void RemoveFront();

	//deletes all messages in the queue
	void ClearQueue();

	//
	void UpdateMessageTime(float dt);

	//returns the size of the queue
	int GetSize();

	//returns true if queue is empty
	bool IsEmpty();
};

