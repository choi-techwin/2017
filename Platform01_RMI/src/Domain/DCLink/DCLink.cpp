
#include "DCLink.h"


DCLink::DCLink(){
	cout<<"DCLink::DCLink-" << this->getID() << endl;
}

DCLink::~DCLink(){
}

int DCLink::initialize() {
	return 0;
}

vector<Event> DCLink::generateEventQueue()
{
	vector<Event> eventQueue;
	for (vector<EventTargetID>::iterator itr=this->eventTargetIDVector.begin(); itr!=this->eventTargetIDVector.end(); itr++) {
		Event event;
		event.setType(eDCLINK_1);
		event.setSourceID(this->getID());
		event.setTargetID(itr->getComponentID());
		event.setTargetSchedulerID(itr->getSchedulerID());
		eventQueue.push_back(event);
		cout << "DCLink::generateEventQueue-pEvent->getType()" << event.getType() << endl;
		cout << "DCLink::generateEventQueue-pEvent->getSourceID()" << event.getSourceID() << endl;
		cout << "DCLink::generateEventQueue-pEvent->getTargetID()" << event.getTargetID() << endl;
		cout << "DCLink::generateEventQueue-pEvent->getTargetSchedulerID()" << event.getTargetSchedulerID() << endl;
	}
	cout << "DCLink:: " << this->getID() << endl;

	return eventQueue;
}
