/*
 * EventTarget.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef EVENTTARGET_H_
#define EVENTTARGET_H_

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


class EventTarget {
private:
	int id;
	vector<Event*> events;

	void append(vector<Event*> other) {
		for (vector<Event*>::iterator itr=other.begin(); itr!=other.end(); itr++) {
			this->events.push_back((*itr));
		}
	}
protected:
	void setEvent(Event& event) {}

	virtual void processEvent(Event* pEvent) {};
	virtual void processFunctionEvent(Event* pEvent) {};

	virtual vector<Event*> generateEvents() {
		vector<Event*> events;
		return events;
	}
	virtual vector<Event*> generateFunctionEvents() {
		vector<Event*> events;
		return events;
	}


public:
	EventTarget(int id): id(id) {}
	virtual ~EventTarget() {}
	virtual void initialize() {}

	int getId() { return this->id; }
	void setId() { this->id = id; }

	void processAllEvent(Event* pEvent) {
		this->processEvent(pEvent);
		this->processFunctionEvent(pEvent);
	}
	vector<Event *> generateAllEvents() {
		this->append(this->generateEvents());
		this->append(this->generateFunctionEvents());
		return this->events;
	}
};



#endif /* EVENTTARGET_H_ */
