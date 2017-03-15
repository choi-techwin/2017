#include "PWM.h"


PWM::PWM(){
	cout<<"PWM::PWM-" << this->getID() << endl;
}
PWM::~PWM(){
}

int PWM::initialize() {
	return 0;
}

vector<Event> PWM::generateEventQueue() {
	vector<Event> eventQueue;
	for (vector<EventTargetID>::iterator itr=this->eventTargetIDVector.begin(); itr!=this->eventTargetIDVector.end(); itr++) {
		Event event;
		event.setType(ePWM_1);
		event.setSourceID(this->getID());
		event.setTargetID(itr->getComponentID());
		event.setTargetSchedulerID(itr->getSchedulerID());
		eventQueue.push_back(event);
		cout << "PWM::generateEventQueue-pEvent->getType()" << event.getType() << endl;
		cout << "PWM::generateEventQueue-pEvent->getSourceID()" << event.getSourceID() << endl;
		cout << "PWM::generateEventQueue-pEvent->getTargetID()" << event.getTargetID() << endl;
		cout << "PWM::generateEventQueue-pEvent->getTargetSchedulerID()" << event.getTargetSchedulerID() << endl;
	}
	cout << "PWM:: " << this->getID() << endl;

	return eventQueue;
}

void PWM::processEvent(Event event) {
	cout << "PWM::processEvent-pEvent->getID()" << event.getType() << endl;
	cout << "PWM::processEvent-pEvent->getSourceID()" << event.getSourceID() << endl;
	cout << "PWM::processEvent-pEvent->getTargetID()" << event.getTargetID() << endl;
	cout << "PWM::processEvent-pEvent->getTargetSchedulerID()" << event.getTargetSchedulerID() << endl;
}
