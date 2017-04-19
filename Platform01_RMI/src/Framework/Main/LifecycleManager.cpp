/*
 * LifecycleManagerSuper.cpp
 *
 *  Created on: 2017. 1. 29.
 *      Author: Sungwoon Choi
 */
#include "LifecycleManager.h"

#include "../../Domain/DCLink/DCLink.h"
#include "../../Domain/PWM/PWM.h"

static Scheduler scheduler1;
static Scheduler scheduler2;
static Scheduler scheduler3;
static Scheduler scheduler4;
static Scheduler scheduler5;
static DCLink dcLink1;
static DCLink dcLink2;
static DCLink dcLink3;
static DCLink dcLink4;
static DCLink dcLink5;
static PWM pwm1;
static PWM pwm2;
static PWM pwm3;
static PWM pwm4;
static PWM pwm5;

LifecycleManagerFramework::LifecycleManagerFramework() {
}

LifecycleManagerFramework::~LifecycleManagerFramework() {
}

void LifecycleManagerFramework::registerSchedulers() {
	this->mainScheduler.addScheduler(&scheduler1);
}

void LifecycleManagerFramework::registerComponents() {
	this->mainScheduler.addComponent(&dcLink1);
	this->mainScheduler.addComponent(&pwm1);

	scheduler1.addComponent(&dcLink2);
	scheduler1.addComponent(&pwm2);
	cout << "LifecycleManager::registerComponents()" << endl;
}

void LifecycleManagerFramework::associateComponents() {
	pwm1.addEventSource(&dcLink1);
	pwm2.addEventSource(&dcLink2);
	cout << "LifecycleManager::associateComponents()" << endl;
}

void LifecycleManagerFramework::configureComponents() {
	this->mainScheduler.configureSchedulers();
	cout << "LifecycleManager::configureComponents()" << endl;
}
void LifecycleManagerFramework::initializeComponents() {
	dcLink1.initialize();
	dcLink2.initialize();
	pwm1.initialize();
	pwm2.initialize();
}

int LifecycleManagerFramework::initialize() {
	this->registerSchedulers();
	this->registerComponents();
	this->associateComponents();
	this->configureComponents();
	this->initializeComponents();
	return 0;
}

int LifecycleManagerFramework::run() {
	mainScheduler.run();
	return 0;
}



