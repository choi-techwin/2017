/*
 * LifecycleManagerSuper.cpp
 *
 *  Created on: 2017. 1. 29.
 *      Author: Sungwoon Choi
 */
#include "LifecycleManager.h"

LifecycleManagerFramework::LifecycleManagerFramework(): EventTarget(typeid(*this)) {
}

LifecycleManagerFramework::~LifecycleManagerFramework() {
}

void LifecycleManagerFramework::configureComponents() {
	this->mainScheduler.configureSchedulers();
}

void LifecycleManagerFramework::initializeSchedulers() {
	this->mainScheduler.initializeSchedulers();
}

void LifecycleManagerFramework::initializeComponents() {
	for (ComponentMap::iterator itr=this->components.begin(); itr!=this->components.end(); itr++) {
		itr->second->initialize();
	}
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


