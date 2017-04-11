#pragma once

#include "Sensor.h"
#include "../../Framework/Scheduler/Event.h"

class Actuator: public Sensor
{

public:
	Actuator() {}
	virtual ~Actuator() {}
	virtual int initialize() { return 0; }

	virtual void actuate(Event *pEvent) {}
};

