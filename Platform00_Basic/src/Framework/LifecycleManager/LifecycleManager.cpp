/*
 * LifecycleManagerSuper.cpp
 *
 *  Created on: 2017. 1. 29.
 *      Author: Sungwoon Choi
 */
#include "LifecycleManager.h"

LifecycleManagerFramework::LifecycleManagerFramework() {
}

LifecycleManagerFramework::~LifecycleManagerFramework() {
}

void LifecycleManagerFramework::configureComponents() {
	this->mainScheduler.configureSchedulers();
	cout << "LifecycleManager::configureComponents()" << endl;
}

void LifecycleManagerFramework::initializeSchedulers() {
	this->mainScheduler.initializeSchedulers();
}

int LifecycleManagerFramework::initialize() {
	this->registerSchedulers();
	this->registerComponents();
	this->associateComponents();
	this->configureComponents();
	this->initializeSchedulers();
	this->initializeComponents();
	return 0;
}

int LifecycleManagerFramework::run() {
	mainScheduler.run();
	return 0;
}


