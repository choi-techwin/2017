/*
 * exception.h
 *
 *  Created on: 2017. 3. 31.
 *      Author: choi.sungwoon
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
#include <iostream>
#include <map>
using namespace std;

static map<int, string> exceptionTypeMsges;
static map<int, string> exceptionCauseMsges;

class Exception: public exception {
private:

	int type;
	int componentId;
	int methodId;
	int cause;
public:
	enum EExceptionType {eFile, ePARSER, eLEX};
	enum EExceptionCause {eFILEOPEN, eFILEREAD, eFILEWRITE};

	Exception(int type) {
		this->type = type;
		this->componentId = 0;
		this->methodId = 0;
		this->cause = 0;
	}
	Exception(int type, int componentId, int methodId, int cause) {
		this->type = type;
		this->componentId = componentId;
		this->methodId = methodId;
		this->cause = cause;
	}
	virtual ~Exception() throw() {
	}

	void setLocation(int componentId, int methodId) {
		this->componentId = componentId;
		this->methodId = methodId;
	}
	void setCause(int cause) {
		this->cause = cause;
	}
	virtual void what() {
		cout << type << componentId << methodId << cause;
	}
};

#endif /* EXCEPTION_H_ */
