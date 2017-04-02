/*
 * Lex.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef LEX_H_
#define LEX_H_ "LEX_H_"

#include <string>
#include <fstream>
using namespace std;

#include "Exception.h"

#define BLANKS " \t\n\r"
#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'
#define BEGIN '{'
#define END '}'
#define PERIOD '.'
#define ZERO '0'
#define NINE '9'

#define PATHSEPARATOR "/"
#define EXTENSION ".txt"

class Lex {
private:
	ifstream* pFin;
	ofstream* pFout;

	char lookahead;
	int tabCount;

	bool isBlank(char c) {
		string token;
		token.append(BLANKS);
		if (token.find(c) != string::npos) return true;
		return false;
	}
	bool isBegin(char c) {
		if (c == BEGIN) return true;
		return false;
	}
	bool isEnd(char c) {
		if (c == END) return true;
		return false;
	}
	bool isDelimeter(char c) {
		if (this->isBlank(c)) return true;
		if (this->isBegin(c)) return true;
		if (this->isEnd(c)) return true;
		return false;
	}
	bool isDigit(char c) {
		if (c >= ZERO && c <= NINE) return true;
		return false;
	}
	bool isPeriod(char c) {
		if (c == PERIOD) return true;
		return false;
	}

	void readBlanks() {
		while(this->isBlank(this->lookahead) && !pFin->eof()) {
			pFin->get(this->lookahead);
		}
	}
	string readDigits() {
		string token;
		while (this->isDigit(this->lookahead) && !pFin->eof()) {
			token.append(1, this->lookahead);
			pFin->get(this->lookahead);
		}
		return token;
	}
	string readPeriod() {
		string token;
		if (this->isPeriod(this->lookahead) && !pFin->eof()) {
			token.append(1, this->lookahead);
			pFin->get(this->lookahead);
		}
		return token;
	}
	string readChars() {
		string token;
		while(!this->isDelimeter(this->lookahead) && !pFin->eof()) {
			token.append(1, this->lookahead);
			pFin->get(this->lookahead);
		}
		return token;
	}
	string readBeginToken() {
		string token;
		if (this->isBegin(this->lookahead) && !pFin->eof()) {
			token.append(1, this->lookahead);
			pFin->get(this->lookahead);
		}
		return token;
	}
	string readEndToken() {
		string token;
		if (this->isEnd(this->lookahead) && !pFin->eof()) {
			token.append(1, this->lookahead);
			pFin->get(this->lookahead);
		}
		return token;
	}


	void tabIndentation() {
		this->tabCount++;
	}
	void untabIndentation() {
		this->tabCount--;
	}
	void writeIndentation() {
		for (int i=0; i<this->tabCount; i++) {
			pFout->put(TAB);
		}
	}

	string getFullName(string path, string objectName) {
		string fullName;
		fullName.append(path);
		fullName.append(PATHSEPARATOR);
		fullName.append(objectName);
		fullName.append(EXTENSION);
		return fullName;
	}

public:
	Lex(): pFin(0), pFout(0), lookahead(BLANKS[0]), tabCount(0) {}
	virtual ~Lex() {}

	void openIn(string path, string fileName) throw() {
		string fullName = this->getFullName(path, fileName);

		this->pFin = new ifstream();
		this->pFin->open(fullName.c_str());
		if (!this->pFin->is_open())
			throw Exception(LEX_H_, "openIn", fullName);
	}
	bool eof() { return pFin->eof(); }
	void closeIn() {
		this->pFin->close();
		if (this->pFin != 0)
			delete this->pFin;
	}

	string readBegin() {
		string token;
		this->readBlanks();
		token = this->readBeginToken();
		return token;
	}
	string readEnd() {
		string token;
		this->readBlanks();
		token = this->readEndToken();
		return token;
	}
	string readInt() {
		string token;
		this->readBlanks();
		token = this->readDigits();
		return token;
	}
	string readFloat() {
		string token;
		this->readBlanks();
		token.append(this->readDigits());
		token.append(this->readPeriod());
		token.append(this->readDigits());
		return token;
	}
	string readString() {
		string token;
		this->readBlanks();
		token = this->readChars();
		return token;
	}

	void openOut(string path, string fileName) throw() {
		string fullName = this->getFullName(path, fileName);

		this->pFout = new ofstream();
		this->pFout->open(fullName.c_str());
		if (!this->pFout->is_open())
			throw Exception(LEX_H_, "openOut", fullName);
		this->tabCount = 0;
	}
	void closeOut() {
		this->pFout->close();
		if (this->pFout != 0)
			delete this->pFout;
	}

	void writeBegin() {
		(*pFout) << SPACE << BEGIN << NEWLINE;
		tabIndentation();
	}
	void writeEnd() {
		untabIndentation();
		this->writeIndentation();
		(*pFout) << END << NEWLINE;
	}
	void writeKey(string token) {
		this->writeIndentation();
		(*pFout) << token;
	}
	void writeValue(string token) {
		(*pFout) << SPACE << token;
		pFout->put(NEWLINE);
	}
};

#endif /* LEX_H_ */
