
#include "Main.h"

MainApp::MainApp() {

}

MainApp::~MainApp() {

}

int MainApp::initialize() {
	this->lifecycleManager.initialize();
	return 0;
}

void MainApp::run() {
	this->lifecycleManager.run();
}

int main() {
	MainApp main;
	main.initialize();
	main.run();
}
