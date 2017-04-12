#include "PWM.h"


PWM::PWM(){
	cout<<"PWM::PWM-" << this->getID() << endl;
}
PWM::~PWM(){
}

int PWM::initialize() {
	cout<<"PWM::initialize-" << this->getID() << endl;
	return 0;
}

void PWM::prepareEvents() {
//	this->addEvent(ePWM_1, NULL);
//	cout << "PWM::prepareEvents: EventType " << ePWM_1 << endl;
//	cout << "                    SourceID " << this->getID() << endl;
}

void PWM::processEvent(Event event) {
	cout << "PWM::processEvent: EventType " << event.getType() << endl;
	cout << "                   SourceID " << event.getSourceID() << endl;
	cout << "                   TargetID " << event.getTargetID() << endl;
	cout << "                   SchedulerID " << event.getTargetSchedulerID() << endl;
}
