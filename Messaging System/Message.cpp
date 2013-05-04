#include "Message.h"



Message::Message(){
	fromID = -1;
	toID = -1;
	timeToDelivery = -1;
	message = -1;
	p = 0;
}

Message::Message(int from, int to, float timeUntilDelivery, int mess){
	fromID = from;
	toID = to;
	timeToDelivery = timeUntilDelivery;
	message = mess;
	p = 0;
}

Message::~Message(){
}
