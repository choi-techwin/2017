/*
 * LifecycleManager.cpp
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#include "LifecycleManagerFramework.h"

LifecycleManagerFramework::LifecycleManagerFramework(): EventTarget(typeid(*this)) {

}

LifecycleManagerFramework::~LifecycleManagerFramework() {

}

void LifecycleManagerFramework::registerSchedulersFramework() {
	this->addScheduler(&(this->mainScheduler));
}

void LifecycleManagerFramework::registerComponentsFramework() {
	// Framework Components
	this->addComponent(this);
}

void LifecycleManagerFramework::associateComponentsFramework() {

}

void LifecycleManagerFramework::generateEvents() {

}

void LifecycleManagerFramework::processEvent(Event event) {

}

int LifecycleManagerFramework::initializeFramework() {
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

void LifecycleManagerFramework::addScheduler(Scheduler* pScheduler) {
	mainScheduler.addScheduler(pScheduler);
}
void LifecycleManagerFramework::addComponent(Component* pComponent) {
	pComponent->setSchedulerID(this->mainScheduler.getID());
	this->components.insert(Make_pair(pComponent->getID(), pComponent));
	mainScheduler.addComponent(pComponent);
}
void LifecycleManagerFramework::addComponent(Component* pComponent, Scheduler* pScheduler) {
	pComponent->setSchedulerID(pScheduler->getID());
	this->components.insert(Make_pair(pComponent->getID(), pComponent));
	pScheduler->addComponent(pComponent);
}

void LifecycleManagerFramework::registerSchedulers() {
	this->registerSchedulersFramework();
	this->registerSchedulersTechnical();
	this->registerSchedulersDomain();
	this->registerSchedulersApp();
}

void LifecycleManagerFramework::registerComponents() {
	// register schedulers as components including the mainScheduler
	SchedulerMap schedulerMap = this->mainScheduler.getSchedulerMap();
	for (SchedulerMap::Iterator itr=schedulerMap.begin(); itr!=schedulerMap.end(); itr++) {
		this->addComponent(itr->second);
	}

	// Application Components
	this->registerComponentsFramework();
	this->registerComponentsTechnical();
	this->registerComponentsDomain();
	this->registerComponentsApp();
}

void LifecycleManagerFramework::associateComponents() {
	this->associateComponentsFramework();
	this->associateComponentsTechnical();
	this->associateComponentsDomain();
	this->associateComponentsApp();
}

void LifecycleManagerFramework::configureComponents() {
	mainScheduler.configureSchedulers();
}

void LifecycleManagerFramework::initializeComponents() {
	for (ComponentMap::Iterator itr=this->components.begin(); itr!=this->components.end(); itr++) {
		itr->second->initialize();
	}
}




