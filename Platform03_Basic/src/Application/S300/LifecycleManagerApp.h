/*
 * LifecycleManagerS300.h
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#ifndef APPLICATION_LIFECYCLEMANAGERAPP_H_
#define APPLICATION_LIFECYCLEMANAGERAPP_H_

#include "../../Domain/LifecycleManagerDomain/LifecycleManagerDomain.h"

class LifecycleManagerApp: public LifecycleManagerDomain {
protected:

public:
	LifecycleManagerApp();
	virtual ~LifecycleManagerApp();
	int initialize();

	// initial Sequence
	void registerSchedulersApp();
	void registerComponentsApp();
	void associateComponentsApp();
};

#endif /* APPLICATION_LIFECYCLEMANAGERAPP_H_ */
