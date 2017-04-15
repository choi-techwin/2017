#include "Component.h"
#include <cxxabi.h>

static int gComponentIDCounter = 0;

Component::Component(const type_info& typeInfo): typeInfo(typeInfo) {
	this->ID = gComponentIDCounter++;
	this->state = eCOMPONENT_RUNNING;

	int status;
	this->typeName = abi::__cxa_demangle(typeInfo.name(), 0, 0, &status);
}

Component::~Component() {
}
