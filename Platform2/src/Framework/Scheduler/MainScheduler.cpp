
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
	cout<<"MainScheduler::initialize-" << this->getID() << endl;
	return 0;
}

void  MainScheduler::addScheduler(Scheduler *pScheduer) {
	this->schedulerMap.insert(make_pair(pScheduer->getID(), pScheduer));
}

void MainScheduler::configureSchedulers() {

	for (map<int, Scheduler *>::iterator itr = this->schedulerMap.begin(); itr!=this->schedulerMap.end(); itr++ ) {
		Scheduler *pScheduler = itr->second;
		pScheduler->configureComponents();
	}
}

void MainScheduler::initializeSchedulers() {
	for (map<int, Scheduler *>::iterator itr = this->schedulerMap.begin(); itr!=this->schedulerMap.end(); itr++ ) {
		Scheduler *pScheduler = itr->second;
		pScheduler->initialize();
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

//		char c;
//		scanf("%c", &c);
	}

	for (vector<thread *>::iterator itrThread = threadVector.begin(); itrThread != threadVector.end(); itrThread++) {
		(*itrThread)->join();
	}
}
