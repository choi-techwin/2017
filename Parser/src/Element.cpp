/*
 * Element.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */
#include "Element.h"

Element::Element() {}
Element::~Element() {}

bool Element::isArray() { return false; }
bool Element::isStructure() { return false; }

const string& Element::getKey() const {return key;}
void Element::setKey(const string& key) {this->key = key;}

const string& Element::getValue() const {return value;}
void Element::setValue(const string& value) {this->value = value;}

void Element::read(Lex& lex, string key) throw() {
	this->setKey(key);
	string value = lex.readString();
	if (value.empty())
		throw Exception(ELEMENT_H_, "read-value", key);
	this->setValue(value);
}
void Element::write(Lex& lex) throw() {
	lex.writeKey(this->key);
	lex.writeValue(this->value);
}



