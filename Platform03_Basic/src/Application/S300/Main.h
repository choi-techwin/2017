/*
 * Main.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#ifndef FRAMEWORK_LIFECYCLEMANAGER_MAIN_H_
#define FRAMEWORK_LIFECYCLEMANAGER_MAIN_H_

#include "LifecycleManagerApp.h"

class Main {
private:
	LifecycleManagerApp lifecycleManagerApp;

public:
	Main();
	virtual ~Main();
	int initialize();

	void run();
};

#endif /* FRAMEWORK_LIFECYCLEMANAGER_MAIN_H_ */
