/*
 * Element.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef ELEMENT_H_
#define ELEMENT_H_ "ELEMENT_H_"

#include "Exception.h"
#include "Lex.h"
#include <string>
using namespace std;

class Element {
private:
	string key;
	string value;
public:
	Element() {}
	virtual ~Element() {}

	virtual bool isStructure() { return false; }

	const string& getKey() const {return key;}
	void setKey(const string& key) {this->key = key;}

	const string& getValue() const {return value;}
	void setValue(const string& value) {this->value = value;}

	virtual void read(Lex& lex, string key) throw() {
		this->setKey(key);
		string value = lex.readString();
		if (value.empty())
			throw Exception(ELEMENT_H_, "read-value", key);
		this->setValue(value);
	}
	virtual void write(Lex& lex) throw() {
		lex.writeKey(this->key);
		lex.writeValue(this->value);
	}
};

#endif /* ELEMENT_H_ */
