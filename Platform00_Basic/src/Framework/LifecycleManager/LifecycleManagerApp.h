/*
 * LifecycleManagerS300.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#ifndef APPLICATION_LIFECYCLEMANAGERS300_H_
#define APPLICATION_LIFECYCLEMANAGERS300_H_

#include "../../Framework/LifecycleManager/LifecycleManager.h"

class LifecycleManagerApp: public LifecycleManagerFramework {
public:
	LifecycleManagerApp();
	virtual ~LifecycleManagerApp();

	void registerSchedulers();
	void registerComponents();
	void associateComponents();
	void initializeComponents();
};

#endif /* APPLICATION_LIFECYCLEMANAGERS300_H_ */
