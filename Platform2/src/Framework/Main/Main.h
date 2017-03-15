#pragma once

#include "LifecycleManager.h"

class Main {
private:
	LifecycleManager lifecycleManager;
public:
	Main();
	virtual ~Main();
	virtual int initialize();
	virtual void run();
};
