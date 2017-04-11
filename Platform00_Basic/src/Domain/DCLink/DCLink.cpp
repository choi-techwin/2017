
#include "DCLink.h"


DCLink::DCLink(){
	cout<<"DCLink::DCLink-" << this->getID() << endl;
}

DCLink::~DCLink(){
}

int DCLink::initialize() {
	cout<<"DCLink::initialize-" << this->getID() << endl;
	return 0;
}

void DCLink::prepareEvents()
{
		this->addEvent(eDCLINK_1, NULL);
		cout << "DCLink::prepareEvents: EventType " << eDCLINK_1 << endl;
		cout << "                       SourceID " << this->getID() << endl;
}
