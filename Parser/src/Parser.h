/*
 * Parser.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Lex.h"
#include <iostream>
#include <map>
#include <sstream>
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

	virtual void readBody(string key) {
		this->setKey(key);
		string value = pLex->readString();
		if (value.empty()) throw new exception();
		this->setValue(value);
	}
	virtual void write() {
		cout << this->getValue() << endl;
	}
};

class Structure: public Element {
private:
	map<string, Element*> elements;
public:
	Structure(Lex* pLex): Element(pLex) {}
	virtual ~Structure() {}

	Element* getElement(string key) {
		return this->elements.find(key)->second;
	}
	void addElement(Element *pElement) {
		this->elements.insert(make_pair(pElement->getKey(), pElement));
	}

	string readKey() {
		// read key
		string key = pLex->readString();
		if (key.empty()) throw new exception();
		return key;
	}
	Element *generateElement() {
		// read key
		string key = this->readKey();
		// element or structure
		Element* pElement = 0;
		if (pLex->readBegin().empty()) {
			pElement = new Element(this->pLex);
		} else {
			pElement = new Structure(this->pLex);
		}
		// read body
		pElement->readBody(key);
		return pElement;
	}

	void readBody(string key) {
		this->setKey(key);
		// read while(not end);
		while (pLex->readEnd().empty() && !pLex->eof()) {
			Element* pElement = generateElement();
			this->addElement(pElement);
		}
	}

	void write() {
		cout << "{" << endl;
		for (map<string, Element*>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
			cout << (*itr).second->getKey();
			(*itr).second->write();
		}
		cout << "}" << endl;
	}
};



class Parser {
private:
	Lex* pLex;
	ifstream fin;
	string path, objectName;

	Structure* pStructure;
private:
	void open(string path, string objectName) {
		this->path = path;
		this->objectName = objectName;

		string fullName;
		fullName.append(path);
		fullName.append("/");
		fullName.append(objectName);
		fullName.append(".txt");
		this->fin.open(fullName.c_str());
		if (!this->fin.is_open())
			throw new exception();
	}
	void close() {
		fin.close();
	}

public:
	Parser(string path, string objectName) {
		this->open(path, objectName);
		this->pLex = new Lex(&this->fin);
		this->pStructure = new Structure(pLex);
	}
	virtual ~Parser() {
		this->close();
		delete(this->pStructure);
	}

	void read() {
		string key = this->pStructure->readKey();
		if (key != objectName) throw new exception();
		this->pStructure->readBody(key);
	}

	void write() {
		cout << this->pStructure->getKey();
		this->pStructure->write();
	}
};


#endif /* PARSER_H_ */
