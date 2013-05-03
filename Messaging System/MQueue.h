#ifndef MQUEUE_H
#define MQUEUE_H

#include <vector>
#include "CMessage.h"

class MQueue{
public:
	std::vector<CMessage*> queue;

	MQueue(){}
	~MQueue(){}

	//push in
	void addToBack(CMessage *message){
		queue.push_back(message);
		sort();
	}
	//pop out
	void takeFromFront(){
		CMessage* temp;
		temp = queue[0];
		queue.erase(queue.begin());
		delete temp;
	}
	//sort
	void sort(){
		if(queue.size() <= 1)
			return;

		CMessage* tempMess = new CMessage();

		for(unsigned x = 0; x < queue.size()-1; x++){
			for(unsigned y = x+1; y < queue.size(); y++){
				if(queue[y]->timeUntilDelivery <= queue[x]->timeUntilDelivery){
					tempMess = queue[x];
					queue[x] = queue[y];
					queue[y] = tempMess;
				}
			}
		}

		//delete tempMess;
	}
	//top of queue
	CMessage* returnFront(){
		return queue[0];
	}
	//back of queue
	CMessage* returnBack(){
		return queue[queue.size()-1];
	}
	//size
	int returnSize(){
		return queue.size();
	}
	void clearQueue(){
		/*for(unsigned x = 0; x < queue.size(); x++){
			takeFromFront();
		}*/
		queue.clear();
	}
};

#endif