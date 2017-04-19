#pragma once

#include "../../Common/Utility/Collection.h"
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

	SchedulerMap getSchedulerMap() { return this->schedulerMap; }
	void addScheduler(Scheduler *pScheduer);
	void configureSchedulers();

	void run();
};
