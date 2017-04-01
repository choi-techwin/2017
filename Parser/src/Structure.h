/*
 * Structure.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include <string>
using namespace std;

class Element {
private:
	string key;
	string value;
protected:
	Lex* pLex;
public:
	Element(Lex* pLex): pLex(pLex) {}
	virtual ~Element() {}

	const string& getKey() const {return key;}
	void setKey(const string& key) {this->key = key;}

	const string& getValue() const {return value;}
	void setValue(const string& value) {this->value = value;}

	virtual string& getValue(string key) {
		return this->value;
	}
	virtual Element* getStructure(string key) {
		return this;
	}

	string readKey() throw() {
		// read key
		string key = pLex->readString();
		if (key.empty()) throw Exception(2);
		return key;
	}
	virtual void readBody(string key) throw() {
		this->setKey(key);
		string value = pLex->readString();
		if (value.empty()) throw Exception(3);
		this->setValue(value);
	}
	virtual void write() throw() {
		cout << " " << this->getValue() << endl;
	}
};

class Structure: public Element {
private:
	map<string, Element*> elements;
public:
	Structure(Lex* pLex): Element(pLex) {}
	virtual ~Structure() {}

	Structure* getSubStructure(string key) {
		return (Structure *)this->elements.find(key)->second;
	}
	string& getSubValue(string key) {
		return (string &)this->elements.find(key)->second->getValue();
	}

	void addElement(Element *pElement) {
		this->elements.insert(make_pair(pElement->getKey(), pElement));
	}

	Element *generateElement() throw() {
		// element or structure
		Element* pElement = 0;
		if (pLex->readBegin().empty()) {
			pElement = new Element(this->pLex);
		} else {
			pElement = new Structure(this->pLex);
		}
		return pElement;
	}

	void readBody(string key) throw() {
		this->setKey(key);
		// read while(not end);
		while (pLex->readEnd().empty() && !pLex->eof()) {
			string fieldKey = this->readKey();
			Element* pElement = generateElement();
			pElement->readBody(fieldKey);
			this->addElement(pElement);
		}
	}

	void write() throw() {
		cout << " {" << endl;
		for (map<string, Element*>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
			cout << (*itr).second->getKey();
			(*itr).second->write();
		}
		cout << "}" << endl;
	}
};






#endif /* STRUCTURE_H_ */
