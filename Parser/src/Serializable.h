/*
 * Serializable.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

#include "Structure.h"
#include <string>
#include <sstream>
using namespace std;

class Serializable {
protected:
	string key;
	Structure *pStructure;

public:
	Serializable(string key): key(key), pStructure(0) {}
	virtual ~Serializable() {}

	string& getKey() { return this->key; }

	virtual void read() {};

	void operator<<(Structure* pOther) {
		this->pStructure = pOther;
		this->read();
	}


	Structure* getStructure(string key) {
		return this->pStructure->getSubStructure(key);
	}
	int getInt(string key) {
		string token = this->pStructure->getSubValue(key);
		int result;
		stringstream ss;
		ss << token;
		ss >> result;
		return result;
	}
	float getFloat(string key) {
		string token = this->pStructure->getSubValue(key);
		float result;
		stringstream ss;
		ss << token;
		ss >> result;
		return result;
	}
	string getString(string key) {
		string result = this->pStructure->getSubValue(key);
		return result;
	}

};




#endif /* SERIALIZABLE_H_ */
