
#include <vector>
#include <stdio.h>
#include <thread>
using namespace std;

#include "MainScheduler.h"

MainScheduler::MainScheduler()
{
	cout<<"MainScheduler::MainScheduler-" << this->getID() << endl;
	this->addScheduler(this);
}

MainScheduler::~MainScheduler() {
}

int MainScheduler::initialize()
{
	return 0;
}

void MainScheduler::configureSchedulers() {
	cout << "MainScheduler::configureSchedulers() - this->schedulerMap.size() " << this->schedulerMap.size() << endl;
	map<int, Scheduler *>::iterator itr = this->schedulerMap.begin();
	for (unsigned i=0; i<this->schedulerMap.size(); i++ ) {
		Scheduler *pScheduler = itr->second;
		cout << "MainScheduler::configureSchedulers() - ID " << pScheduler->getID() << endl;
		pScheduler->configureComponents();
		itr++;
	}
}

void MainScheduler::sendEventToScheduler() {
	if (this->mainEventQueue.empty()) return;

	Event event = this->mainEventQueue.front();
	Scheduler *pScheduler = (this->schedulerMap.find(event.getTargetSchedulerID()))->second;
	pScheduler->processEvent(event);
	this->mainEventQueue.erase(this->mainEventQueue.begin());
}

void MainScheduler::collectEventsFromSchedulers() {
	for (map<int, Scheduler *>::iterator itrSchedulerMap = this->schedulerMap.begin(); itrSchedulerMap!=this->schedulerMap.end(); itrSchedulerMap++) {
		vector<Event> eventQueue = itrSchedulerMap->second->generateEventQueue();
		for (vector<Event>::iterator itrEventQueue=eventQueue.begin(); itrEventQueue!=eventQueue.end(); itrEventQueue++) {
			Event event = *itrEventQueue;
			this->mainEventQueue.push_back(event);
		}
	}
}

void MainScheduler::run() {
	vector<thread *> threadVector;
	for (map<int, Scheduler *>::iterator itrScheduler = this->schedulerMap.begin(); itrScheduler != this->schedulerMap.end(); itrScheduler++) {
		thread *t = new thread(&Scheduler::run, itrScheduler->second);
		threadVector.push_back(t);
	}

	while (this->getState() != eCOMPONENT_STOPPED) {
		// MainScheduler Components
		this->sendEvent();
		this->collectEvents();
		// Schedulers
		this->sendEventToScheduler();
		this->collectEventsFromSchedulers();

		char c;
		scanf("%c", &c);
	}

	for (vector<thread *>::iterator itrThread = threadVector.begin(); itrThread != threadVector.end(); itrThread++) {
		(*itrThread)->join();
	}
}
