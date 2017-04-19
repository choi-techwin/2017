#pragma once

#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>

using namespace std;

#include "../../Common/Utility/Map.h"
#include "../Scheduler/Scheduler.h"
#include "../Scheduler/MainScheduler.h"
#include "../Component/Component.h"
#include "../Component/EventTarget.h"

typedef Map<int, Component*> ComponentMap;

class LifecycleManagerFramework: public EventTarget {
private:
	ComponentMap components;
	MainScheduler mainScheduler;
protected:
	// As a component
	virtual void generateEvents() {}
	virtual void processEvent(Event event) {}

	void addScheduler(Scheduler* pScheduler) {
		this->mainScheduler.addScheduler(pScheduler);
		this->components.insert(make_pair(pScheduler->getID(), pScheduler));
	}
	void addComponent(Component* pComponent) {
		this->mainScheduler.addComponent(pComponent);
		this->components.insert(make_pair(pComponent->getID(), pComponent));
	}
	void addComponent(Component* pComponent, Scheduler* pScheduler) {
		pScheduler->addComponent(pComponent);
		this->components.insert(make_pair(pComponent->getID(), pComponent));
	}

	virtual void registerSchedulers() = 0;
	virtual void registerComponents() = 0;
	virtual void associateComponents() = 0;
	void configureComponents();
	void initializeSchedulers();
	void initializeComponents();

public:
	LifecycleManagerFramework();
	virtual ~LifecycleManagerFramework();

	virtual int initialize();
	virtual int run();
};
