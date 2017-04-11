#pragma once

#include <queue>
using namespace std;

#include "Device.h"
#include "../../Framework/Scheduler/Event.h"

class Sensor: public Device
{
private:
	queue<Event *> eventQueue;
public:
	Sensor() {};
	virtual ~Sensor() {}
	virtual int initialize() { return 0; }

	virtual queue<Event *> generateEvents() { return this->eventQueue;  }
};

