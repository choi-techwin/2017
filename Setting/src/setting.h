/*
 * Setting.h
 *
 *  Created on: 2017. 3. 23.
 *      Author: choi.techwin
 */

#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

static string MAIN_KEY = "MAIN";

static string BEGIN = "{";
static string END = "}";
static string DELIMETER = " ";
static char DELIMETERS[] = {' ', '\n', '\t', '\r', '\0'};


class Tokenizer {
private:
	ifstream fin;
	bool isDelimeter(char c) {
		for (int i=0; i<7; i++) {
			if (c == DELIMETERS[i])
				return true;
		}
		return false;
	}
	string removeDelimeters() {
		char c;
		this->fin >> c;
		while (isDelimeter(c)) {
			this->fin >> c;
		}
		string result;
		result += c;
		return result;
	}

public:
	Tokenizer() {
	}
	virtual ~Tokenizer() {}

	void open(string fileName) {
		fin.open(fileName.c_str());
		fin.is_open();
	}
	string read() {
		string token;
		this->fin >> token;
		return token;
	}
	bool eof() {
		return this->fin.eof();
	}
};

class Header {
private:
	string className;
	string ObjectID;
public:
	Header() {
	}
	virtual ~Header() {
	}

	string getClassName() {
		return this->className;
	}
	string getObjectID() {
		return this->ObjectID;
	}

	void read(Tokenizer *pTokenizer, string key) {
		className = pTokenizer->read();
	}
};

class Element {
private:
	string key;
	string value;
	void setValue(string value) { this->value = value; }
protected:
	void setKey(string key) { this->key = key; }
public:
	Element() {}
	virtual ~Element() {}

	virtual bool isElement() { return true; }
	string getKey() {return this->key;}
	string getValue() {return this->value;}

	virtual void read(Tokenizer *pTokenizer, string key, string value) {
		this->setKey(key);
		this->setValue(value);
	}
};

class Structure: public Element {
private:
	vector<Element *> elements;
public:
	Structure() {}
	virtual ~Structure() {}

	vector<Element *>* getPElements() { return &(this->elements);}
	virtual bool isElement() { return false; }

	void read(Tokenizer *pTokenizer, string key, string value) {
		this->setKey(key);

		Element* pElement = 0;
		string token1 = pTokenizer->read();
		while ((token1 != END) && !pTokenizer->eof()) {
			string token2 = pTokenizer->read();
			if (token2 == BEGIN) {
				pElement = new Structure();
			} else {
				pElement = new Element();
			}
			pElement->read(pTokenizer, token1, token2);
			this->elements.push_back(pElement);
			token1 = pTokenizer->read();
		}
	}

	Element* getElement(string key) {
		for (vector<Element *>::iterator itr=elements.begin(); itr!=elements.end(); itr++) {
			Element* pElement = *itr;
			if (pElement->getKey() == key)
				return pElement;
		}
		return 0;
	}
};

class Parser {
private:
	Tokenizer tokenizer;
	Header header;
	Structure body;
	Element *pCurrent, *pParent;

public:
	Parser() {
		this->pCurrent = 0;
		this->pParent = 0;
	}
	virtual ~Parser() {
	}

	void read(string key) {
		string fileName = "rsc/"+ key + ".txt";
		if (tokenizer.open(fileName)) {
			header.read(&tokenizer, key);
			body.read(&tokenizer, key, BEGIN);

			this->pCurrent = &this->body;
		}
	}

	Element *getPElement(string key) {
		if (pCurrent->isElement()) {
			if (pCurrent->getKey() == key) {
				return pCurrent;
			}
			return 0;
		}
		vector<Element*> *pElements = ((Structure*)pCurrent)->getPElements();
		for (vector<Element *>::iterator itr=pElements->begin(); itr!=pElements->end(); itr++) {
			if ((*itr)->getKey() == key) {
				return (*itr);
			}
		}
		return 0;
	}
	int getInt(string key) {
		int result;
		Element *pElement = getPElement(key);
		stringstream ss;
		ss << pElement->getValue();
		ss >> result;
		return result;
	}
	float getFloat(string key) {
		float result;
		Element *pElement = getPElement(key);
		stringstream ss;
		ss << pElement->getValue();
		ss >> result;
		return result;
	}
	string getString(string key) {
		string result;
		Element *pElement = getPElement(key);
		result = pElement->getValue();
		return result;
	}
	int getStructure(string key) {
		this->pParent = this->pCurrent;
		this->pCurrent = getPElement(key);
		return 0;
	}
	int getBegin(string key) {
		this->getStructure(key);
		return 0;
	}
	int getEnd() {
		this->pCurrent = this->pParent;
		return 0;
	}

	void writeBegin(string key) {
		cout << key;
		cout << BEGIN;
	}
	void writeEnd() {
		cout << END << DELIMETER;
	}
	void writeInt (string key, int value) {
		stringstream ss;
		ss << value;
		cout << key << DELIMETER << ss.str() << DELIMETER;
	}
	void writeFloat (string key, float value) {
		stringstream ss;
		ss << value;
		cout << key << DELIMETER << ss.str() << DELIMETER;
	}
	void writeString (string key, string value) {
		cout << key << DELIMETER << string(value) << DELIMETER;
	}
};

class Setting {
protected:
	virtual void writeBody(Parser *pParser) = 0;
	virtual void getBody(Parser *pParser) = 0;

	void writeBegin(Parser *pParser, string key) {pParser->writeBegin(key);}
	void writeEnd(Parser *pParser) {pParser->writeEnd();}
	void writeInt(Parser *pParser, string key, int value) {pParser->writeInt(key, value);}
	void writeFloat(Parser *pParser, string key, float value) {pParser->writeFloat(key, value);}
	void writeString(Parser *pParser, string key, string value) {pParser->writeString(key, value);}

	int getBegin(Parser *pParser, string key) 		{ return pParser->getBegin(key);}
	int getEnd(Parser *pParser) 					{ return pParser->getEnd();}
	int getInt(Parser *pParser, string key) 		{ return pParser->getInt(key);}
	float getFloat(Parser *pParser, string key) 	{ return pParser->getFloat(key);}
	string getString(Parser *pParser, string key) 	{ return pParser->getString(key);}
	int getStructure(Parser *pParser, string key) 	{ return pParser->getStructure(key);}

public:
	Setting() {}
	virtual ~Setting() {}

	void write(Parser *pParser, string key) {
		this->writeBegin(pParser, key);
		this->writeBody(pParser);
		this->writeEnd(pParser);
	}

	void get(Parser *pParser, string key) {
		this->getBegin(pParser, key);
		this->getBody(pParser);
		this->getEnd(pParser);
	}
};

class VideoProfile: public Setting {
private:
	int att3;
	float att4;
protected:
	void writeBody(Parser *pParser) {
		this->writeInt(pParser, "att3", att3);
		this->writeFloat(pParser, "att4", att4);
	}
	virtual void getBody(Parser *pParser) {
		att3 = this->getInt(pParser, "att3");
		att4 = this->getFloat(pParser, "att4");
	}
public:
	VideoProfile() {
		this->att3 = 5;
		this->att4 = 2.3;
	}
	virtual ~VideoProfile() {}
};

class VideoManager: public Setting {
private:
	int att1;
	VideoProfile videoProfile;
	float att2;
protected:
	void writeBody(Parser *pParser) {
		this->writeInt(pParser, "att1", att1);
		videoProfile.write(pParser, "videoProfile");
		this->writeFloat(pParser, "att2", att2);
	}
	void getBody(Parser *pParser) {
		this->att1 = this->getInt(pParser, "att1");
		this->videoProfile.get(pParser, "videoProfile");
		this->att2 = this->getFloat(pParser, "att2");
	}

public:
	VideoManager() {
		this->att1 = 5;
		this->att2 = 2.3;
	}
	virtual ~VideoManager() {}
};


#endif /* SETTING_H_ */
