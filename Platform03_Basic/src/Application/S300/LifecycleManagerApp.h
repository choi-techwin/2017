/*
 * LifecycleManagerS300.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#ifndef APPLICATION_LIFECYCLEMANAGERAPP_H_
#define APPLICATION_LIFECYCLEMANAGERAPP_H_

#include "LifecycleManager.h"

class LifecycleManagerApp: public LifecycleManager {
public:
	LifecycleManagerApp();
	virtual ~LifecycleManagerApp();

	void registerSchedulers();
	void registerComponents();
	void associateComponents();
};

#endif /* APPLICATION_LIFECYCLEMANAGERAPP_H_ */
