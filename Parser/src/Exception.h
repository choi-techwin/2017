/*
 * exception.h
 *
 *  Created on: 2017. 3. 31.
 *      Author: choi.sungwoon
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_ "EXCEPTION_H_"

#include <string>
#include <exception>
#include <iostream>

using namespace std;

class Message {
private:
	string moduleName;
	string functionName;
	string cause;

	string message;

	void append(string moduleName, string functionName, string cause) {
		this->moduleName = moduleName;
		this->functionName = functionName;
		this->cause = cause;

		message.append(this->moduleName);
		message.append("::");
		message.append(this->functionName);
		message.append(" ");
		message.append(this->cause);
	}
public:
	Message() {}
	Message(string moduleName, string functionName, string cause) {
		append(moduleName, functionName, cause);
	}

	const string& get() {
		return this->message;
	}
	void set(string moduleName, string functionName, string cause) {
		append(moduleName, functionName, cause);
	}
	void setCause(string& cause) {
		this->cause = cause;
	}

	void show() {
		cout << message << endl;
	}
	void show(string message) {
		this->message = message;
		cout << message << endl;
	}
	void show(string moduleName, string functionName, string cause) {
		append(moduleName, functionName, cause);
		cout << message << endl;
	}

} gMessage;


class Exception: public exception {
public:
	Exception(string cause) {
		gMessage.setCause(cause);
	}
	Exception(string moduleName, string functionName, string cause) {
		gMessage.set(moduleName, functionName, cause);
	}
	virtual ~Exception() throw() {
	}

	void setCause(string& cause) {
		gMessage.setCause(cause);
	}
	const char* what() const throw() {
		return gMessage.get().c_str();
	}
};


#endif /* EXCEPTION_H_ */
