/*
 * LifecycleManagerSuper.cpp
 *
 *  Created on: 2017. 1. 29.
 *      Author: Sungwoon Choi
 */
#include "LifecycleManager.h"

LifecycleManager::LifecycleManager(): EventTarget(typeid(*this)) {
}

LifecycleManager::~LifecycleManager() {
}

void LifecycleManager::configureComponents() {
	this->mainScheduler.configureSchedulers();
}

void LifecycleManager::initializeSchedulers() {
	this->mainScheduler.initializeSchedulers();
}

void LifecycleManager::initializeComponents() {
	for (ComponentMap::iterator itr=this->components.begin(); itr!=this->components.end(); itr++) {
		itr->second->initialize();
	}
}

int LifecycleManager::initialize() {
	this->registerSchedulers();
	this->registerComponents();
	this->associateComponents();
	this->configureComponents();
	this->initializeSchedulers();
	this->initializeComponents();
	return 0;
}

int LifecycleManager::run() {
	mainScheduler.run();
	return 0;
}


