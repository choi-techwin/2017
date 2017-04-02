#pragma once

#include "../Global/ValueObject.h"

class Event: public ValueObject
{
private:
	int type;
	int sourceID;
	int targetID;
	int targetSchedulerID;
	ValueObject *pArg;
	int iArg;

public:
	// constructors
	Event();
	virtual ~Event();

	// methods
	virtual Event *deepCopy();

	// getters & setters
	int getType() { return this->type; }
	void setType(int _type) { this->type = _type; }

	int getSourceID() { return this->sourceID; }
	void setSourceID(int sourceID) { this->sourceID = sourceID; }

	int getTargetID() { return this->targetID; }
	void setTargetID(int targetID) { this->targetID = targetID; }

	int getTargetSchedulerID() { return this->targetSchedulerID; }
	void setTargetSchedulerID(int targetSchedulerID) { this->targetSchedulerID = targetSchedulerID; }

	ValueObject *getPArg() { return this->pArg; }
	void setPArg(ValueObject *pArg) { this->pArg = pArg; }

	int getIArg() { return this->iArg; }
	void setIArg(int iArg) { this->iArg = iArg; }
};
