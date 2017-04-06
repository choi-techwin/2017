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
		throw Exception(SERIALIZABLE_H_, "getValueSerializable-not found", key);
	}
	// associate the serializable with a found structure
	serializable.setStructure(pElement);
	// fill each field
	serializable.read();
}
void Serializable::get(int& result, string key) {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getValue-not found", key);
		return;
	}
	string token = pElement->getValue();
	stringstream ss;		ss << token;
	ss >> result;
}
void Serializable::get(float& result, string key) {
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getValue-not found", key);
		return;
	}
	string token = pElement->getValue();
	stringstream ss;
	ss << token;
	ss >> result;
}
void Serializable::get(string& result, string key){
	Element *pElement = this->pStructure->getElement(key);
	if (pElement==NULL) {
		gMessage.show(SERIALIZABLE_H_, "getValue-not found", key);
		return;
	}
	result = pElement->getValue();
}

void Serializable::get(int result[], int length, string key){
	Array *pElement = (Array*)this->pStructure->getElement(key);
	if (pElement==NULL) {
		throw Exception(SERIALIZABLE_H_, "getValueSerializable-not found", key);
	}
	// associate the serializable with a found structure

	for (int i=0; i<length; i++) {
		string indexKey;
		stringstream ss;
		ss << i;
		ss >> indexKey;
		int r;
		ss << pElement->getElement(indexKey);
		ss >> r;
		result[i] = r;
	}
}

// load data to child serializable structure
void Serializable::set(Serializable& serializable, string key) throw() {
	// clear child serializable structure's elements
	serializable.getStructure()->clearElements();
	// set the child serializable key as a provided key
	serializable.getStructure()->setKey(key);
	// add the child serializable structure as my structure's element
	this->pStructure->addElement(serializable.getStructure());
	// write serializable data to the associated structure
	serializable.write();
}
void Serializable::set(int& value, string key) throw() {
	stringstream ss;
	ss << value;
	string result;
	ss >> result;
	this->pStructure->addElement(key, result);
}
void Serializable::set(float& value, string key) throw() {
	stringstream ss;
	ss << value;
	string result;
	ss >> result;
	this->pStructure->addElement(key, result);
}
void Serializable::set(string& value, string key) throw() {
	this->pStructure->addElement(key, value);
}

