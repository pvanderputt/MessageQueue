#ifndef CDISPATCHER_H
#define CDISPATCHER_H

#include "MQueue.h"
#include "CMessage.h"

#define DISPATCH CDispatcher::dispatch()

class CDispatcher{
public:
	static CDispatcher* dispatch(){
		static CDispatcher dispatch;
		return &dispatch;
	}

	//class will send messages from the top of the queue to the reciever
	MQueue queue;

	~CDispatcher(){
		queue.clearQueue();
	}

	//sends the given message
	//will not send the message if the reciever is no longer there
	void sendMessage(CMessage* message, double deltaT){
		switch(message->message){
		default:
			break;
	}

	//adds a message to the queue
	void addMessage(CMessage* newMessage){
		queue.addToBack(newMessage);
	}

	//updates the queue on what time the clock is at
	//and will deliver any mail needing to be sent
	void updateTime(double deltaT){
		if(queue.queue.size() == 0)
			return 0;

		//send messages that need to be sent
		for(unsigned x = 0; x < queue.queue.size(); x++){
			queue.queue[x]->timeUntilDelivery -= deltaT;
			if(queue.queue[x]->timeUntilDelivery <= 0){
				sendMessage(queue.queue[x], deltaT);
			}
		}

		//delete messages that have been sent
		for(unsigned x = 0; x < queue.queue.size(); x++){
			if(queue.queue[x]->timeUntilDelivery <= 0){
				CMessage* temp;
				temp = queue.queue[x];
				queue.queue.erase(queue.queue.begin() + x);
				delete temp;
				x--;
			}
		}
	}

	//update all units
	void updateUnits(float dt){

	}

	//update everything
	void updateALL(double deltaT){
		//counts the timers on messages in the queue and sends messages
		updateTime(deltaT);
		updateUnits((float)deltaT);
	}

private:
	//next valid ID
	int NVID;

	//get next valid ID
	int getNVID(){
		NVID++;
		return NVID;
	}

	CDispatcher(){
		NVID = -1;
	}
};

#endif