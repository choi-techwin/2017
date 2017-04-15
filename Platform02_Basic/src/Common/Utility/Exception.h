/*
 * Exception.h
 *
 *  Created on: 2017. 4. 15.
 *      Author: choi.sungwoon
 */

#ifndef COMMON_UTILITY_EXCEPTION_H_
#define COMMON_UTILITY_EXCEPTION_H_

#include <string>
#include <exception>
#include <iostream>
using namespace std;

class Message {
private:
	string source;
	string args;
	string targetState;
	string target;
	string function;
	string resultName;
	string value;
	string expression;
public:
	Message(string target, string function, string resultName, string value) {
		expression = target+"::"+function + " - " + resultName + " = " + value;
	}
	void show() {
		cout << expression << endl;
	}
	void show(string target, string function, string resultName, string value) {
		expression = target+"::"+function + " - " + resultName + " = " + value;
		cout << expression << endl;
	}

};

class Exception: public exception {
private:
	string message;
public:
	Exception(): exception() {}
	Exception(string target, string function, string resultName, string value) {
		message = target+"::"+function + " - " + resultName + " = " + value;
	}
	virtual ~Exception() {}

	virtual const char* what() const throw() {
		return message.c_str();
	}
};

#endif /* COMMON_UTILITY_EXCEPTION_H_ */
