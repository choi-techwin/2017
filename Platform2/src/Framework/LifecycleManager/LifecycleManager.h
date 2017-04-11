#pragma once

#include "../Scheduler/Scheduler.h"
#include "../Scheduler/MainScheduler.h"
#include "../Component/Component.h"

class LifecycleManager {
private:
	MainScheduler mainScheduler;
protected:
	void addScheduler(Scheduler* pScheduler) {
		this->mainScheduler.addScheduler(pScheduler);
	}
	void addComponent(Component* pComponent) {
		this->mainScheduler.addComponent(pComponent);
	}
	void addComponent(Component* pComponent, Scheduler* pScheduler) {
		pScheduler->addComponent(pComponent);
	}

	virtual void registerSchedulers() = 0;
	virtual void registerComponents() = 0;
	virtual void associateComponents() = 0;
	void configureComponents();
	void initializeSchedulers();
	virtual void initializeComponents() = 0;

public:
	LifecycleManager();
	virtual ~LifecycleManager();

	virtual int initialize();
	virtual int run();
};
