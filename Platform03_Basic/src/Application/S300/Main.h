/*
 * Main.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#ifndef FRAMEWORK_LIFECYCLEMANAGER_MAIN_H_
#define FRAMEWORK_LIFECYCLEMANAGER_MAIN_H_

class Main {
public:
	Main();
	virtual ~Main();
	virtual int initialize();
	virtual void run();
};

#endif /* FRAMEWORK_LIFECYCLEMANAGER_MAIN_H_ */
