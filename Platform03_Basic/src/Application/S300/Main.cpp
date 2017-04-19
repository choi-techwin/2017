
#include "Main.h"

Main::Main() {

}

Main::~Main() {

}

int Main::initialize() {
	this->lifecycleManagerApp.initializeFramework();
	return 0;
}

void Main::run() {
	this->lifecycleManagerApp.run();
}

int main() {
	Main main;
	main.initialize();
	main.run();
}
