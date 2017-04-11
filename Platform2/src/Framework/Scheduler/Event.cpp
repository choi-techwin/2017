#include "Event.h"

Event::Event() {
	this->type = 0;
	this->sourceID = 0;
	this->targetID = 0;
	this->targetSchedulerID = 0;
	this->pArg = 0;
}

Event::Event(int type, ValueObject* pArg) {
	this->type = type;
	this->sourceID = 0;
	this->targetID = 0;
	this->targetSchedulerID = 0;
	this->pArg = pArg;
}

Event::~Event() {
	if (this->pArg != 0)
		delete this->pArg;
}

