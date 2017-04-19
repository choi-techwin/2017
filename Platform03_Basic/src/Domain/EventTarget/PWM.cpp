#include "PWM.h"


PWM::PWM(): EventTarget(typeid(*this)) {
}

PWM::~PWM(){
}

int PWM::initialize() {
	return 0;
}

void PWM::generateEvents() {
//	this->addEvent(ePWM_1, NULL);
//	cout << "PWM::prepareEvents: EventType " << ePWM_1 << endl;
//	cout << "                    SourceID " << this->getID() << endl;
}

void PWM::processEvent(Event event) {
	cout << this->getTypeName() << "(" << this->getID() << ")::processEvent(src=" << event.getSourceID() << ", type=" << event.getType() << ")" << endl;
}
