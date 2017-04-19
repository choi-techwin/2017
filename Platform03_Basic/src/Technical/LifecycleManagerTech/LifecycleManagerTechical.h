/*
 * LifecycleManagerTech.h
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#ifndef TECHNICAL_LIFECYCLEMANAGERTECHNICAL_H_
#define TECHNICAL_LIFECYCLEMANAGERTECHNICAL_H_

#include "../../Framework/LifecycleManagerFramework/LifecycleManagerFramework.h"
#include "../../Technical/Timer/Timer.h"

class LifecycleManagerTechical: public LifecycleManagerFramework {
protected:
	Timer timer;
public:
	LifecycleManagerTechical();
	virtual ~LifecycleManagerTechical();

	void registerSchedulersTechnical();
	void registerComponentsTechnical();
	void associateComponentsTechnical();
};

#endif /* TECHNICAL_LIFECYCLEMANAGERTECHNICAL_H_ */
