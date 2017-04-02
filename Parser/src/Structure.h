/*
 * Structure.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_ "STRUCTURE_H_"

#include <string>
using namespace std;

class Element {
private:
	string key;
	string value;
public:
	bool isStructure;
	Element()  { isStructure = false; }
	virtual ~Element() {}

	const string& getKey() const {return key;}
	void setKey(const string& key) {this->key = key;}

	const string& getValue() const {return value;}
	void setValue(const string& value) {this->value = value;}

	virtual void read(Lex *pLex, string key) throw() {
		this->setKey(key);
		string value = pLex->readString();
		if (value.empty())
			throw Exception(STRUCTURE_H_, "Element::read", key);
		this->setValue(value);
	}
	virtual void write(Lex *pLex) throw() {
		pLex->writeKey(this->key);
		pLex->writeValue(this->value);
	}
};

class Structure: public Element {
private:
	map<string, Element*> elements;
public:
	Structure() { this->isStructure = true; }
	virtual ~Structure() {}

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

	void read(Lex *pLex, string key) throw() {
		this->setKey(key);
		// read while(not end);
		while (pLex->readEnd().empty() && !pLex->eof()) {
			// read key
			string elementdKey = pLex->readString();
			if (elementdKey.empty())
				throw Exception(STRUCTURE_H_, "Structure::read", key);
			// generate new element
			Element* pElement = 0;
			if (pLex->readBegin().empty()) {
				pElement = new Element();
			} else {
				pElement = new Structure();
			}
			// read element data
			pElement->read(pLex, elementdKey);
			// add element
			this->addElement(pElement);
		}
	}
	void write(Lex *pLex) throw() {
		for (map<string, Element*>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
			pLex->writeKey((*itr).second->getKey());
			if ((*itr).second->isStructure) {
				pLex->writeBegin();
				(*itr).second->write(pLex);
				pLex->writeEnd();
			} else {
				pLex->writeValue((*itr).second->getValue());

			}
		}
	}
};

#endif /* STRUCTURE_H_ */
