#pragma once
#include <iostream>
using namespace std;

enum EComponentState { eCOMPONENT_IDLE, eCOMPONENT_RUNNING, eCOMPONENT_STOPPED };

class Component {
private:
	int ID;
	EComponentState state;
public:
	Component();
	virtual ~Component();
	virtual int initialize() = 0;

	int getID() { return this->ID; }
	EComponentState getState() { return this->state; }
	void setState(EComponentState state) { this->state = state; }

	virtual bool isEventSource() { return false; }
	virtual bool isEventTarget() { return false; }
};

