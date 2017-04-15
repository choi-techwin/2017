#pragma once

#include "../../Common/Utility/Map.h"
#include "../../Common/Utility/Queue.h"
using namespace std;

#include "Scheduler.h"

typedef Map<int, Scheduler*> SchedulerMap;
typedef Queue<Event> EventQueue;

class MainScheduler: public Scheduler {
private:
	EventQueue mainEventQueue;
	SchedulerMap schedulerMap;

protected:
	// As a component
	virtual void generateEvents() {}
	virtual void processEvent(Event event) {}

	// As a scheduler
	virtual void collectEventsFromSchedulers();
	virtual void distributeEventToScheduler();

public:
	MainScheduler();
	virtual ~MainScheduler();
	int initialize();

	void addScheduler(Scheduler *pScheduer);
	void configureSchedulers();
	void initializeSchedulers();

	void run();
};
