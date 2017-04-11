/*
 * LifecycleManagerSuper.cpp
 *
 *  Created on: 2017. 1. 29.
 *      Author: Sungwoon Choi
 */
#include "LifecycleManager.h"

LifecycleManager::LifecycleManager() {
}

LifecycleManager::~LifecycleManager() {
}

void LifecycleManager::configureComponents() {
	this->mainScheduler.configureSchedulers();
	cout << "LifecycleManager::configureComponents()" << endl;
}

void LifecycleManager::initializeSchedulers() {
	this->mainScheduler.initializeSchedulers();
}

int LifecycleManager::initialize() {
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


