/*
 * Structure.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */

#include "Structure.h"
#include "Array.h"

Structure::Structure() {}
Structure::~Structure() {
}
bool Structure::isStructure() { return true; }

void Structure::clearElements() {
	for (map<string, Element*>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
		if (itr->second->isStructure()) {
			Structure* pStructure = (Structure*)itr->second;
			pStructure->clearElements();
		}
	}
	this->elements.clear();
}
Element *Structure::getElement(string key) throw() {
	map<string, Element*>::iterator itr = this->elements.find(key);
	if (itr==elements.end())
		return NULL;
	return itr->second;
}
void Structure::addElement(Element *pElement) throw() {
	this->elements.insert(make_pair(pElement->getKey(), pElement));
}
void Structure::addElement(string key, string value) throw() {
	Element *pElement = new Element();
	pElement->setKey(key);
	pElement->setValue(value);
	this->elements.insert(make_pair(key, pElement));
}

void Structure::read(Lex& lex, string key) throw() {
	this->setKey(key);
	// read while(not end);
	while (lex.readEnd().empty() && !lex.eof()) {
		// read key
		string elementdKey = lex.readString();
		if (elementdKey.empty())
			throw Exception(STRUCTURE_H_, "Structure::read", key);
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
		pElement->read(lex, elementdKey);
		// add element
		this->addElement(pElement);
	}
}
void Structure::write(Lex& lex) throw() {
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



