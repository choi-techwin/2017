/*
 * EventTargetID.h
 *
 *  Created on: 2017. 1. 30.
 *      Author: Sungwoon Choi
 */

#ifndef FRAMEWORK_COMPONENT_EVENTTARGETID_H_
#define FRAMEWORK_COMPONENT_EVENTTARGETID_H_

class EventTargetID {
private:
	int componentID;
	int schedulerID;
public:
	EventTargetID(int componentID, int schedulerID) {
		this->componentID = componentID;
		this->schedulerID = schedulerID;
	}

	int getComponentID() const {
		return this->componentID;
	}

	void setComponentID(int componentID) {
		this->componentID = componentID;
	}

	int getSchedulerID() const {
		return this->schedulerID;
	}

	void setSchedulerID(int schedulerID) {
		this->schedulerID = schedulerID;
	}
};

#endif /* FRAMEWORK_COMPONENT_EVENTTARGETID_H_ */
