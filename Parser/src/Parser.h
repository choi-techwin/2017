/*
 * Parser.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef PARSER_H_
#define PARSER_H_  "PARSER_H_"

#include "Lex.h"
#include "Serializable.h"

using namespace std;

class Parser: public Serializable {
private:
	Lex lex;
	string path, fileName;
public:
	Parser() {}
	virtual ~Parser() {}

	void openIn(string path, string fileName) throw() {
		this->path = path;
		this->fileName = fileName;
		this->lex.openIn(path, fileName);
	}
	// store parsed data to a class
	void read() throw() {
		this->getStructure().read(this->lex, this->fileName);
	}
	void load(Serializable& serializable, string key) throw() {
		this->getValue(serializable, key);
	}
	void closeIn() throw() {
		this->getStructure().clearElements();
		this->lex.closeIn();
	}

	void openOut(string path, string fileName) throw() {
		this->path = path;
		this->fileName = fileName;
		this->lex.openOut(path, fileName);

		this->getStructure().setKey(this->fileName);
	}
	// write data to a file
	void store(Serializable& serializable, string key) throw() {
		this->setValue(serializable, key);
	}
	void write() throw() {
		this->getStructure().write(this->lex);
	}
	void closeOut() throw() {
		this->getStructure().clearElements();
		this->lex.closeOut();
	}


};


#endif /* PARSER_H_ */
