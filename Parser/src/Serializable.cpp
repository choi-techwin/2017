/*
 * Serializable.cpp
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */

#include "Serializable.h"
#include "Array.h"

Serializable::Serializable() {pStructure = 0;}
Serializable::~Serializable() {}

Structure* Serializable::getStructure() { return this->pStructure; }
void Serializable::setStructure(Structure* pStructure) { this->pStructure = pStructure; }

// get Serializable data from Structures

void Serializable::get(Serializable& serializable, string key) throw() {
	// find a child structure named key
	Structure *pElement = (Structure*) this->pStructure->getElement(key);
	if (pElement==NULL) {
		throw Exception(SERIALIZABLE_H_, "getValueStructure-not found", key);
	}
	gMessage.show("Serializable", "pStructure", key);
	// associate the serializable with a found structure
	serializable.setStructure(pElement);
	// fill each field
	serializable.read();
}
void Serializable::get(int& result, string key) {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getInt-not found", key);
		return;
	}
	gMessage.show("Serializable", "getInt", key);
	string token = pElement->getValue();
	stringstream ss;		ss << token;
	ss >> result;
}
void Serializable::get(float& result, string key) {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getFloat-not found", key);
		return;
	}
	gMessage.show("Serializable", "getFloat", key);
	string token = pElement->getValue();
	stringstream ss;
	ss << token;
	ss >> result;
}
void Serializable::get(string& result, string key){
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getString-not found", key);
		return;
	}
	gMessage.show("Serializable", "getString", key);
	result = pElement->getValue();
}

void Serializable::get(int result[], int length, string key){
	Array *pArray = (Array*)this->pStructure->getElement(key);
	if (pArray==NULL) {
		throw Exception(SERIALIZABLE_H_, "getArray-not found", key);
	}
	gMessage.show("Serializable", "getArray", pArray->getKey());
	// associate the serializable with a found structure

	for (int i=0; i<length; i++) {
		string indexKey;
		stringstream ss;
		ss << i;
		ss >> indexKey;
		Element *pElement = pArray->getElement(indexKey);
		if (pElement==NULL) {
			throw Exception(SERIALIZABLE_H_, "getArrayElement-not found", key, indexKey);
		}
		if (pElement->isStructure()) {

		} else if (pElement->isArray()) {

		} else {
			ss.clear();
			int r;

			ss << pElement->getValue();
			ss >> r;

			result[i] = r;
			cout << "Serializable " << "getArrayElement " << i << " " <<  result[i] << endl;
		}
	}
}

// load data to child serializable structure
void Serializable::set(Serializable& serializable, string key) throw() {
	Structure* pElement = (Structure*) this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Structure();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
		serializable.setStructure(pElement);
	}
	gMessage.show("Serializable", "setStructure", key);
	// write serializable data to the associated structure
	serializable.write();
}
void Serializable::set(int& value, string key) throw() {
	Element* pElement = this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Element();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
	}
	stringstream ss;
	ss << value;
	string result;
	ss >> result;
	pElement->setValue(result);
	gMessage.show("Serializable", "setInt", key, result);
}
void Serializable::set(float& value, string key) throw() {
	Element* pElement = this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Element();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
	}
	stringstream ss;
	ss << value;
	string result;
	ss >> result;
	pElement->setValue(result);
	gMessage.show("Serializable", "setInt", key, result);
}
void Serializable::set(string& result, string key) throw() {
	Element* pElement = this->pStructure->getElement(key);
	if (pElement == NULL) {
		pElement = new Element();
		pElement->setKey(key);
		this->pStructure->addElement(pElement);
	}
	pElement->setValue(result);
	gMessage.show("Serializable", "setInt", key, result);
}

void Serializable::set(int value[], int length, string key) throw() {
	stringstream ss;
	Array* pArray = (Array*) this->pStructure->getElement(key);
	if (pArray == NULL) {
		pArray = new Array();
		pArray->setKey(key);
		this->pStructure->addElement(pArray);
	}
	gMessage.show("Serializable", "setArray", key);
	for (int i=0; i<length; i++) {
		string elementKey;
		ss.clear();
		ss << i;
		ss >> elementKey;
		Element* pElement = pArray->getElement(elementKey);
		if (pElement == NULL) {
			pElement = new Element();
			pElement->setKey(elementKey);
			pArray->addElement(pElement);
		}
		string  result;
		ss.clear();
		ss << value[i];
		ss >> result;
		pElement->setValue(result);
		cout << "Serializable " << "setArrayElement " << elementKey << "(" << i << ") " << value[i] << "(" << result << ")" << endl;
	}
	// add the child serializable structure as my structure's element
}

