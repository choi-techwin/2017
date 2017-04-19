#ifndef TECHNICAL_LIFECYCLEMANAGER_H_
#define TECHNICAL_LIFECYCLEMANAGER_H_

#include "../../Common/Utility/Collection.h"
#include "../Component/Component.h"
#include "../Component/EventTarget.h"
#include "../Scheduler/MainScheduler.h"
#include "../Scheduler/Scheduler.h"

typedef Map<int, Component*> ComponentMap;

class LifecycleManagerFramework: public EventTarget {
private:
	ComponentMap components;

protected:
	MainScheduler mainScheduler;

	void addScheduler(Scheduler* pScheduler);
	void addComponent(Component* pComponent);
	void addComponent(Component* pComponent, Scheduler* pScheduler);

	void registerSchedulersFramework();
	void registerComponentsFramework();
	void associateComponentsFramework();

	virtual void registerSchedulersTechnical() = 0;
	virtual void registerComponentsTechnical() = 0;
	virtual void associateComponentsTechnical() = 0;

	virtual void registerSchedulersDomain() = 0;
	virtual void registerComponentsDomain() = 0;
	virtual void associateComponentsDomain() = 0;

	virtual void registerSchedulersApp() = 0;
	virtual void registerComponentsApp() = 0;
	virtual void associateComponentsApp() = 0;

	void registerSchedulers();
	void registerComponents();
	void associateComponents();
	void configureComponents();
	void initializeComponents();

	// as an EventTarget
	void generateEvents();
	void processEvent(Event event);

public:
	LifecycleManagerFramework();
	virtual ~LifecycleManagerFramework();
	int initializeFramework();

	virtual int run();
};

#endif /* TECHNICAL_LIFECYCLEMANAGER_H_ */
