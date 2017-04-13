#pragma once

#include "LifecycleManager.h"

class MainApp {
private:
	LifecycleManager lifecycleManager;
public:
	MainApp();
	virtual ~MainApp();
	virtual int initialize();
	virtual void run();
};
