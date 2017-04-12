
#include "../../Framework/LifecycleManager/Main.h"
#include "../../Framework/LifecycleManager/LifecycleManagerApp.h"

static 	LifecycleManagerApp lifecycleManagerApp;

Main::Main() {
}

Main::~Main() {
}

int Main::initialize() {
	lifecycleManagerApp.initialize();
	return 0;
}

void Main::run() {
	lifecycleManagerApp.run();
}


