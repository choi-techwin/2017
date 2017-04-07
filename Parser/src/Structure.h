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
//#include "Array.h"
#include <string>
#include <map>

using namespace std;

class Array;

class Structure: public Element {
protected:
	map<string, Element*> elements;
public:
	Structure();
	virtual ~Structure();
	bool isStructure();

	void clearElements();
	Element *getElement(string key) throw();
	void addElement(Element *pElement) throw();

	void read(Lex& lex, string key) throw();
	void write(Lex& lex) throw();
};

#endif /* STRUCTURE_H_ */
