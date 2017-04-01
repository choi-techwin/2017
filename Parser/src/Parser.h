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

#include "Exception.h"
#include "Serializable.h"
#include "Structure.h"
using namespace std;


class Parser {
private:
	Lex lex;
	string path, fileName;
	Structure structure;
private:
	void open(string path, string fileName) throw() {
		this->path = path;
		this->fileName = fileName;
		this->lex.open(path, fileName);
	}
	void close() throw() {
		this->lex.close();
	}

public:
	Parser(): structure(&lex) {
	}
	virtual ~Parser() {
	}

	void read(string path, string fileName) throw() {
		// open file
		this->open(path, fileName);
		// top level structures
		this->structure.readBody(fileName);
		// close file
		this->close();
	}
	void write() throw() {
		cout << this->structure.getKey();
		this->structure.write();
	}
	void operator>>(Serializable& serializable) {
		serializable << this->structure.getSubStructure(serializable.getKey());
	}
};


#endif /* PARSER_H_ */
