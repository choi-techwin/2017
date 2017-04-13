#include "Scheduler.h"

Scheduler::Scheduler()
{
	cout<<"Scheduler::Scheduler-" << this->getID() << endl;
}

Scheduler::~Scheduler()
{
}

int Scheduler::initialize()
{
	cout<<"Scheduler::initialize-" << this->getID() << endl;
	return 0;
}

void Scheduler::addComponent(Component *pComponent)
{
	if (pComponent->isEventSource()) {
		this->eventSourceMap.insert(make_pair(pComponent->getID(), (EventSource *)pComponent));
	}
	if (pComponent->isEventTarget()) {
		this->eventTargetMap.insert(make_pair(pComponent->getID(), (EventTarget *)pComponent));
	}
}

void Scheduler::configureComponents()
{
	// associate EventTarget to EventSource
	for (map<int, EventTarget *>::iterator itrTarget = this->eventTargetMap.begin(); itrTarget!=this->eventTargetMap.end(); itrTarget++) {
		vector<EventSource *> eventSourceVector = itrTarget->second->getEventSourceVector();
		for (vector<EventSource *>::iterator itrSource = eventSourceVector.begin(); itrSource!=eventSourceVector.end(); itrSource++) {
			(*itrSource)->addEventTargetID(itrTarget->second->getID(), this->getID());
		}
	}
}

// scheduling
void Scheduler::distributeEvent() {
	if (this->eventQueue.empty()) return;

	Event event = this->eventQueue.deQueue();
	EventTarget *pEventTarget = this->eventTargetMap.find(event.getTargetID())->second;
	if (pEventTarget == 0) return;
	pEventTarget->processEvent(event);
}

void Scheduler::prepareEvents() {
	// get source events from eventSources
	for (map<int, EventSource *>::iterator itr = this->eventSourceMap.begin(); itr!=this->eventSourceMap.end(); itr++) {
		vector<Event> eventQueue = itr->second->generateEvents();
		for (vector<Event>::iterator itrEventQueue=eventQueue.begin(); itrEventQueue!=eventQueue.end(); itrEventQueue++) {
			Event event = *itrEventQueue;
			this->addEvent(event);
		}
	}
}

vector<Event> Scheduler::generateEvents() {
	return this->getSourceEvents();
}

void Scheduler::run(void)
{
	while (this->getState() != eCOMPONENT_STOPPED) {
		this->distributeEvent();
		this->prepareEvents();

		Sleep(500);
		char c;
		cin >> c;
	}
}
