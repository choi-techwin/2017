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
	void distributeEventToScheduler();
	void collectEventsFromSchedulers();

public:
	MainScheduler();
	virtual ~MainScheduler();
	int initialize();

	void addScheduler(Scheduler *pScheduer);
	void configureSchedulers();
	void initializeSchedulers();

	void run();
};
