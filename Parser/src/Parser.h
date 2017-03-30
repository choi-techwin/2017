/*
 * Parser.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Lex.h"

class Parser {
private:
	Lex lex;
	ifstream fin;
public:
	Parser(): lex() {

	}
	virtual ~Parser() {}

	void open(string fileName) {
		this->fin.open(fileName.c_str());
		if (!this->fin.is_open())
			throw new exception();
	}
	void close() {
		fin.close();
	}

	int readInt() {
		return lex.readInt(fin);
	}
};



#endif /* PARSER_H_ */
