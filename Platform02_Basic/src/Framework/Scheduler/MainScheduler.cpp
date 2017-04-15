
#include "MainScheduler.h"

#include <thread>
using namespace std;

MainScheduler::MainScheduler() {
	this->addScheduler(this);
}

MainScheduler::~MainScheduler() {
}

int MainScheduler::initialize()
{
	return 0;
}

void  MainScheduler::addScheduler(Scheduler *pScheduer) {
	this->schedulerMap.insert(make_pair(pScheduer->getID(), pScheduer));
}

void MainScheduler::configureSchedulers() {
	for (SchedulerMap::iterator itr = this->schedulerMap.begin(); itr!=this->schedulerMap.end(); itr++ ) {
		Scheduler *pScheduler = itr->second;
		pScheduler->configureComponents();
	}
}

void MainScheduler::initializeSchedulers() {
	for (SchedulerMap::iterator itr = this->schedulerMap.begin(); itr!=this->schedulerMap.end(); itr++ ) {
		Scheduler *pScheduler = itr->second;
		pScheduler->initialize();
	}
}

void MainScheduler::collectEventsFromSchedulers() {
	for (SchedulerMap::iterator itrScheduler = this->schedulerMap.begin(); itrScheduler!=this->schedulerMap.end(); itrScheduler++) {
		EventQueue* pEventQueue = itrScheduler->second->getEvents();
		for (EventQueue::Iterator itrEvent = pEventQueue->begin(); itrEvent!= pEventQueue->end(); itrEvent++) {
			this->mainEventQueue.enQueue(*itrEvent);
		}
		pEventQueue->clear();
	}
}

void MainScheduler::distributeEventToScheduler() {
	if (this->mainEventQueue.empty()) return;

	Event event = this->mainEventQueue.deQueue();
	Scheduler *pScheduler = (this->schedulerMap.find(event.getTargetSchedulerID()))->second;
	pScheduler->putEvent(event);
}

void MainScheduler::run() {
	vector<thread *> threadVector;
	for (SchedulerMap::iterator itrScheduler = this->schedulerMap.begin(); itrScheduler != this->schedulerMap.end(); itrScheduler++) {
		if (itrScheduler->second == this) continue;
		thread *t = new thread(&Scheduler::run, itrScheduler->second);
		threadVector.push_back(t);
	}

	while (this->getState() != eCOMPONENT_STOPPED) {
		// MainScheduler Components
		this->distributeEvent();
		this->collectEvents();
		// Schedulers
		this->distributeEventToScheduler();
		this->collectEventsFromSchedulers();
	}

	for (vector<thread *>::iterator itrThread = threadVector.begin(); itrThread != threadVector.end(); itrThread++) {
		(*itrThread)->join();
	}
}
