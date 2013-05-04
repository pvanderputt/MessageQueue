#include "PostOffice.h"



PostOffice::PostOffice(){
}

PostOffice::~PostOffice(){
}

void PostOffice::AddMail(Message* m){
	post.AddMessage(m);
}

void PostOffice::Update(float dt){
	
}

void PostOffice::SendMail(){

}
