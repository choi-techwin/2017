#pragma once

enum EDeviceState { eDEVICE_IDLE, eDEVICE_RUNNING, eDEVICE_STOPPED };

class Device
{
private:
	int type;
	int ID;
	EDeviceState eState;
public:
	Device();
	virtual ~Device();
	virtual int initialize() { return 0; }

	int getID() { return this->ID; }
	EDeviceState getState() { return this->eState; }
	void setState(EDeviceState _eState) { this->eState = _eState; }
};

