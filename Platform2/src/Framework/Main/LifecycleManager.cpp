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

LifecycleManager::LifecycleManager() {
}

LifecycleManager::~LifecycleManager() {
}

void LifecycleManager::addScheduler(Scheduler *pScheduler) {
	this->mainScheduler.addScheduler(pScheduler);
}

void LifecycleManager::registerComponents() {
	this->mainScheduler.addComponent(&dcLink1);
	this->mainScheduler.addComponent(&dcLink2);
	this->mainScheduler.addComponent(&pwm1);
	cout << "LifecycleManager::registerComponents()" << endl;
}

void LifecycleManager::associateComponents() {
	pwm1.addEventSource(&dcLink1);
	pwm1.addEventSource(&dcLink2);
	cout << "LifecycleManager::associateComponents()" << endl;
}

void LifecycleManager::configureComponents() {
	this->mainScheduler.configureSchedulers();
	cout << "LifecycleManager::configureComponents()" << endl;
}
void LifecycleManager::initializeComponents() {
	dcLink1.initialize();
	dcLink2.initialize();
	pwm1.initialize();
}

int LifecycleManager::initialize() {
	this->registerComponents();
	this->associateComponents();
	this->configureComponents();
	this->initializeComponents();
	return 0;
}

int LifecycleManager::run() {
	mainScheduler.run();
	return 0;
}



