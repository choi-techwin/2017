
#include "Main.h"

Main::Main() {
}
Main::~Main() {}

int Main::initialize() {
	this->lifecycleManager.initialize();
	return 0;
}

void Main::run() {
	this->lifecycleManager.run();
}

int main() {
	Main main;
	main.initialize();
	main.run();
}
