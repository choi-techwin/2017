#pragma once

#include "../../Framework/Component/EventTarget.h"

enum EPWMEventType { ePWM_0 = __COUNTER__, ePWM_1 = __COUNTER__};
class PWM: public EventTarget {
public:
	PWM();
	virtual ~PWM();
	int initialize();

	vector<Event> generateEventQueue();
	void processEvent(Event event);

};
