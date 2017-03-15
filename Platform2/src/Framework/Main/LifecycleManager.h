#pragma once


#include "../Scheduler/Scheduler.h"
#include "../Scheduler/MainScheduler.h"

#include <map>
using namespace std;

class LifecycleManager {
private:
	MainScheduler mainScheduler;
protected:
	void addScheduler(Scheduler *pScheduler);

	virtual void registerComponents();
	virtual void associateComponents();
	virtual void configureComponents();
	virtual void initializeComponents();

public:
	LifecycleManager();
	virtual ~LifecycleManager();

	virtual int initialize();
	virtual int run();
};
