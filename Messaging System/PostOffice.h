#pragma once

#include "MessageQueue.h"



class PostOffice{
public:
	MessageQueue post;
public:
	PostOffice();
	~PostOffice();

	//adds a message to the queue
	void AddMail(Message* m);

	//update time
	void Update(float dt);

	//sends all messages out that are needed to be sent
	void SendMail();
};

