#pragma once

#include "LifecycleManager.h"

class MainApp {
private:
	LifecycleManagerFramework lifecycleManager;
public:
	MainApp();
	virtual ~MainApp();
	virtual int initialize();
	virtual void run();
};
