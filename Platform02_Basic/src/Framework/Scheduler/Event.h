#pragma once

#include "../../Common/Global/ValueObject.h"

class Event: public ValueObject
{
private:
	int type;
	int sourceID;
	int sourceSchedulerID;
	int targetID;
	int targetSchedulerID;
	ValueObject *pArg;

public:
	// constructors
	Event();
	Event(int type, ValueObject* pArg);
	virtual ~Event();

	// getters & setters
	int getType() { return this->type; }
	void setType(int _type) { this->type = _type; }

	int getSourceID() { return this->sourceID; }
	void setSourceID(int sourceID) { this->sourceID = sourceID; }
	int getSourceSchedulerID() { return this->sourceSchedulerID; }
	void setSourceSchedulerID(int sourceSchedulerID) { this->sourceSchedulerID = sourceSchedulerID; }

	int getTargetID() { return this->targetID; }
	void setTargetID(int targetID) { this->targetID = targetID; }
	int getTargetSchedulerID() { return this->targetSchedulerID; }
	void setTargetSchedulerID(int targetSchedulerID) { this->targetSchedulerID = targetSchedulerID; }

	ValueObject *getPArg() { return this->pArg; }
	void setPArg(ValueObject *pArg) { this->pArg = pArg; }
};
