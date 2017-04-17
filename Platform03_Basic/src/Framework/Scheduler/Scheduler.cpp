#include "Scheduler.h"

Scheduler::Scheduler(): EventTarget(typeid(*this))  {
}

Scheduler::~Scheduler() {
}

int Scheduler::initialize()
{
	this->addComponent(this);
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
	for (EventTargetMap::iterator itrTarget = this->eventTargetMap.begin(); itrTarget!=this->eventTargetMap.end(); itrTarget++) {
		EventSourceVector* pEventSourceVector = itrTarget->second->getEventSourceVector();
		for (EventSourceVector::iterator itrSource = pEventSourceVector->begin(); itrSource!=pEventSourceVector->end(); itrSource++) {
			(*itrSource)->addEventTargetID(itrTarget->second->getID(), this->getID());
		}
	}
}

void Scheduler::collectEvents() {
	// get source events from eventSources
	for (EventSourceMap::iterator itrEventSource = this->eventSourceMap.begin(); itrEventSource!=this->eventSourceMap.end(); itrEventSource++) {
		EventQueue* pEventQueue = itrEventSource->second->getEvents();
		for (EventQueue::iterator itrEvent=pEventQueue->begin(); itrEvent!=pEventQueue->end(); itrEvent++) {
			this->sourceEventQueue.enQueue(*itrEvent);
		}
		pEventQueue->clear();
	}
}

// scheduling
void Scheduler::distributeEvent() {
	if (this->targetEventQueue.empty()) return;

	Event event = this->targetEventQueue.deQueue();
	EventTarget *pEventTarget = this->eventTargetMap.find(event.getTargetID())->second;
	if (pEventTarget == 0) return;
	pEventTarget->putEvent(event);
}

void Scheduler::run(void)
{
	while (this->getState() != eCOMPONENT_STOPPED) {
		this->distributeEvent();
		this->collectEvents();
	}
}
