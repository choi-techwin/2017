
#include "DCLink.h"


DCLink::DCLink(): EventSource(typeid(*this)) {
}

DCLink::~DCLink(){
}

int DCLink::initialize() {
	return 0;
}

void DCLink::generateEvents()
{
	Sleep(500);
	this->addEvent(eDCLINK_1, NULL);
	EventQueue* pSourceEventQueue = this->getSourceEventQueue();
	for (EventQueue::Iterator itr=pSourceEventQueue->begin();  itr!=pSourceEventQueue->end(); itr++)
		cout << this->getTypeName() << "(" << this->getID() << ")::generateEvents(target=" << itr->getTargetID() << ", type=" << eDCLINK_1 << ")" << endl;
}
