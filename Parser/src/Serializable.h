/*
 * Serializable.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_ "SERIALIZABLE_H_"

#include "Structure.h"
#include <string>
#include <sstream>
using namespace std;

class Serializable {
private:
	Structure structure;
public:
	Serializable() {}
	virtual ~Serializable() {}

	Structure& getStructure() { return this->structure; }
	void setStructure(Structure& structure) { this->structure = structure; }

	// get Serializable data from Structures
	virtual void read()=0;
	void getValue(Serializable& serializable, string key) throw() {
		// find a child structure named key
		Structure *pElement = (Structure*) this->structure.getElement(key);
		if (pElement==NULL) {
			throw Exception(SERIALIZABLE_H_, "getValueSerializable-not found", key);
		}
		// associate the serializable with a found structure
		serializable.setStructure(*pElement);
		// fill each field
		serializable.read();
	}
	void getValue(int& result, string key) {
		Element *pElement = this->structure.getElement(key);
		if (pElement==NULL) {
			MESSAGE.show(SERIALIZABLE_H_, "getValue-not found", key);
			return;
		}
		string token = pElement->getValue();
		stringstream ss;
		ss << token;
		ss >> result;
	}
	void getValue(float& result, string key) {
		Element *pElement = this->structure.getElement(key);
		if (pElement==NULL) {
			MESSAGE.show(SERIALIZABLE_H_, "getValue-not found", key);
			return;
		}
		string token = pElement->getValue();
		stringstream ss;
		ss << token;
		ss >> result;
	}
	void getValue(string& result, string key){
		Element *pElement = this->structure.getElement(key);
		if (pElement==NULL) {
			MESSAGE.show(SERIALIZABLE_H_, "getValue-not found", key);
			return;
		}
		result = pElement->getValue();
	}

	// create Structures from Serializable data
	virtual void write()=0;
	// load data to child serializable structure
	void setValue(Serializable& serializable, string key) throw() {
		// clear child serializable structure's elements
		serializable.getStructure().clearElements();
		// set the child serializable key as a provided key
		serializable.getStructure().setKey(key);
		// add the child serializable structure as my structure's element
		this->structure.addElement(&(serializable.getStructure()));
		// write serializable data to the associated structure
		serializable.write();
	}
	void setValue(int& value, string key) throw() {
		stringstream ss;
		ss << value;
		string result;
		ss >> result;
		this->structure.addElement(key, result);
	}
	void setValue(float& value, string key) throw() {
		stringstream ss;
		ss << value;
		string result;
		ss >> result;
		this->structure.addElement(key, result);
	}
	void setValue(string& value, string key) throw() {
		this->structure.addElement(key, value);
	}
};

#endif /* SERIALIZABLE_H_ */
