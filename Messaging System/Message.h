#pragma once



class Message{
public:
	int fromID;
	int toID;
	float timeToDelivery;
	int message;
	void* p;

	Message();
	Message(int from, int to, float timeUntilDelivery, int mess);
	~Message();
};

//MessageComparison struct for comparing two messages in a priority queue
//the messages are compared by the value timeToDelivery
//the operator for the return is flipped so that the queue is sorted lowest to highest
struct MessageComparison{
	bool operator()(Message* m1, Message* m2){
		return m1->timeToDelivery > m2->timeToDelivery;
	}
};