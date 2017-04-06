/*
 * Value.h
 *
 *  Created on: 2017. 4. 3.
 *      Author: choi.sungwoon
 */

#ifndef EVENT_H_
#define EVENT_H_

class Event {
private:
	int type;
	int sourceID;
	int targetID;
	int targetSchedulerID;
	int iArg;
	void *pArg;

public:
	// constructors
	Event() {
		this->type = 0;
		this->sourceID = 0;
		this->targetID = 0;
		this->targetSchedulerID = 0;
		this->iArg = 0;
		this->pArg = 0;
	}
	virtual ~Event() {}

	// getters & setters
	int getType() { return this->type; }
	void setType(int _type) { this->type = _type; }

	int getSourceID() { return this->sourceID; }
	void setSourceID(int sourceID) { this->sourceID = sourceID; }

	int getTargetID() { return this->targetID; }
	void setTargetID(int targetID) { this->targetID = targetID; }

	int getTargetSchedulerID() { return this->targetSchedulerID; }
	void setTargetSchedulerID(int targetSchedulerID) { this->targetSchedulerID = targetSchedulerID; }

	int getIArg() { return this->iArg; }
	void setIArg(int iArg) { this->iArg = iArg; }

	void *getPArg() { return this->pArg; }
	void setPArg(void *pArg) { this->pArg = pArg; }
};



#endif /* EVENT_H_ */
