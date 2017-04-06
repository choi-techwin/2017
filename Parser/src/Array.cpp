/*
 * Array.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */

#include "Array.h"
#include <sstream>

Array::Array() {
}

Array::~Array() {
}

bool Array::isArray() { return true; }

void Array::read(Lex& lex, string key) throw() {
	lex.readIndexEnd();
	lex.readBegin();

	this->setKey(key);
	// read while(not end);
	int index = 0;
	while (lex.readEnd().empty() && !lex.eof()) {
		// generate new element
		Element* pElement = 0;
		if (!lex.readBegin().empty()) {
			pElement = new Structure();
		} else if (!lex.readIndexBegin().empty()) {
			pElement = new Array();
		}
		else {
			pElement = new Element();
		}
		// read element data
		stringstream ss;
		ss << index;
		string key;
		ss >> key;
		pElement->read(lex, key);
		index++;
		// add element
		this->addElement(pElement);
	}
}
void Array::write(Lex& lex) throw() {
	for (map<string, Element*>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
		lex.writeKey((*itr).second->getKey());
		if ((*itr).second->isStructure()) {
			lex.writeBegin();
			(*itr).second->write(lex);
			lex.writeEnd();
		} else if ((*itr).second->isArray()) {
			lex.writeIndexBegin();
			lex.writeIndexEnd();
			(*itr).second->write(lex);
		} else {
			lex.writeValue((*itr).second->getValue());

		}
	}
}

