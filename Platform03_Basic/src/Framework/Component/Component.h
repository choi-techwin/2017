#pragma once
#include <iostream>
#include <typeinfo>

#include "../../Common/Utility/Exception.h"

enum EComponentState { eCOMPONENT_IDLE, eCOMPONENT_RUNNING, eCOMPONENT_STOPPED };

class Component {
private:
	const type_info& typeInfo;
	string typeName;
	int ID;
	int schedulerID;

	EComponentState state;
protected:

public:
	Component(const type_info& typeInfo);
	virtual ~Component();
	virtual int initialize() = 0;

	string getTypeName() { return this->typeName; }
	int getID() { return this->ID; }

	int getSchedulerID() { return this->ID; }
	void setSchedulerID(int schedulerID) { this->schedulerID = schedulerID; }

	EComponentState getState() { return this->state; }
	void setState(EComponentState state) { this->state = state; }

	virtual bool isEventSource() { return false; }
	virtual bool isEventTarget() { return false; }
};

