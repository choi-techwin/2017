/*
 * Structure.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_ "STRUCTURE_H_"

#include "Exception.h"
#include "Element.h"
#include <string>
#include <map>

using namespace std;

class Structure: public Element {
private:
	map<string, Element*> elements;
public:
	Structure() {}
	virtual ~Structure() {}
	bool isStructure() { return true; }

	void clearElements() {
		this->elements.clear();
	}
	Element *getElement(string key) throw() {
		map<string, Element*>::iterator itr = this->elements.find(key);
		if (itr==elements.end())
			return NULL;
		return itr->second;
	}
	void addElement(Element *pElement) throw() {
		this->elements.insert(make_pair(pElement->getKey(), pElement));
	}
	void addElement(string key, string value) throw() {
		Element *pElement = new Element();
		pElement->setKey(key);
		pElement->setValue(value);
		this->elements.insert(make_pair(key, pElement));
	}

	void read(Lex& lex, string key) throw() {
		this->setKey(key);
		// read while(not end);
		while (lex.readEnd().empty() && !lex.eof()) {
			// read key
			string elementdKey = lex.readString();
			if (elementdKey.empty())
				throw Exception(STRUCTURE_H_, "Structure::read", key);
			// generate new element
			Element* pElement = 0;
			if (lex.readBegin().empty()) {
				pElement = new Element();
			} else {
				pElement = new Structure();
			}
			// read element data
			pElement->read(lex, elementdKey);
			// add element
			this->addElement(pElement);
		}
	}
	void write(Lex& lex) throw() {
		for (map<string, Element*>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
			lex.writeKey((*itr).second->getKey());
			if ((*itr).second->isStructure()) {
				lex.writeBegin();
				(*itr).second->write(lex);
				lex.writeEnd();
			} else {
				lex.writeValue((*itr).second->getValue());

			}
		}
	}
};

#endif /* STRUCTURE_H_ */
