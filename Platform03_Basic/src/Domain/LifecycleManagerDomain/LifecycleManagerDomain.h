/*
 * LifecycleManagerDomain.h
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#ifndef DOMAIN_LIFECYCLEMANAGERDOMAIN_LIFECYCLEMANAGERDOMAIN_H_
#define DOMAIN_LIFECYCLEMANAGERDOMAIN_LIFECYCLEMANAGERDOMAIN_H_

#include "../../Technical/LifecycleManagerTech/LifecycleManagerTechical.h"
#include "../EventSource/DCLink.h"
#include "../EventTarget/PWM.h"

class LifecycleManagerDomain: public LifecycleManagerTechical {
protected:
	Scheduler scheduler1;
	Scheduler scheduler2;

	DCLink dcLink0;
	DCLink dcLink1;

	PWM pwm0;
	PWM pwm1;
public:
	LifecycleManagerDomain();
	virtual ~LifecycleManagerDomain();

	void registerSchedulersDomain();
	void registerComponentsDomain();
	void associateComponentsDomain();
};

#endif /* DOMAIN_LIFECYCLEMANAGERDOMAIN_LIFECYCLEMANAGERDOMAIN_H_ */
