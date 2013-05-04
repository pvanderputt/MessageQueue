#include "PostOffice.h"



PostOffice::PostOffice(){}

PostOffice::~PostOffice(){}

void PostOffice::AddMail(Message* m){
	post.AddMessage(m);
}

void PostOffice::Update(float dt){
	post.UpdateMessageTime(dt);

	SendMail();
}

void PostOffice::SendMail(){
	if(post.IsEmpty())
		return;

	while(post.GetFront()->timeToDelivery <= 0){
		DeliverMessage(post.TakeFront());

		if(post.IsEmpty())
			break;
	}
}

void PostOffice::DeliverMessage(Message* m){
	//find the entity 

	//send the entity  m->message or the message

	//if sending the m->message, delete entity

	//otherwise let the entity take care of deletion
}