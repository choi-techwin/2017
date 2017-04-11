#include "Device.h"

static int gDeviceIDCounter = 0;

Device::Device()
{
	this->type = 0;
	this->ID = gDeviceIDCounter++;
	this->eState = eDEVICE_IDLE;
}

Device::~Device()
{
}
