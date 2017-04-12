#include "Component.h"

static int gComponentIDCounter = 0;

Component::Component()
{
	this->ID = gComponentIDCounter++;
	this->state = eCOMPONENT_RUNNING;
}

Component::~Component() {

}
