#pragma once

#include <vector>
#include <map>
using namespace std;

#include "Scheduler.h"

class MainScheduler: public Scheduler {
private:
	vector<Event> mainEventQueue;
	map<int, Scheduler *> schedulerMap;
protected:
	void sendEventToScheduler();
	void collectEventsFromSchedulers();

public:
	MainScheduler();
	virtual ~MainScheduler();
	virtual int initialize();

	void addScheduler(Scheduler *pScheduer) { this->schedulerMap.insert(make_pair(pScheduer->getID(), pScheduer)); }
	void configureSchedulers();

	virtual void run();
};
