
#include "Main.h"
#include "LifecycleManagerApp.h"

static LifecycleManagerApp lifecycleManagerApp;

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

int main() {
	Main main;
	main.initialize();
	main.run();
}
