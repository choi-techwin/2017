#include "Event.h"

Event::Event() {
	this->type = 0;
	this->sourceID = 0;
	this->targetID = 0;
	this->targetSchedulerID = 0;
	this->pArg = 0;
}

Event::~Event() {
	if (this->pArg != 0)
		delete this->pArg;
}

Event *Event::deepCopy() {
	Event *pEvent = new Event();
	pEvent->type=this->type;
	pEvent->sourceID=this->sourceID;
	pEvent->targetID=this->targetID;
	pEvent->targetSchedulerID=this->targetSchedulerID;
	pEvent->pArg = this->pArg->deepCopy();
	return pEvent;
}
