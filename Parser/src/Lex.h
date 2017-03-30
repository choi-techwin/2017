/*
 * Lex.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef LEX_H_
#define LEX_H_

#include <string>
#include <fstream>
using namespace std;

static string BLANK (" \t\n\r\0");
static string BEGIN ("{");
static string END("}");
static string PERIOD(".");

class Lex {
private:
	ifstream* pFin;
	char lookahead;

	bool isBlank(char c) {
		if (string(BLANK).find(c) != string::npos) return true;
		return false;
	}
	bool isBegin(char c) {
		string token;
		token.append(1, c);
		if (token.compare(BEGIN)== 0) return true;
		return false;
	}
	bool isEnd(char c) {
		string token;
		token.append(1, c);
		if (token.compare(END) == 0) return true;
		return false;
	}
	bool isDelimeter(char c) {
		if (this->isBlank(c)) return true;
		if (this->isBegin(c)) return true;
		if (this->isEnd(c)) return true;
		return false;
	}
	bool isDigit(char c) {
		if (c>='0' && c<='9') return true;
		return false;
	}
	bool isPeriod(char c) {
		string token;
		token.append(1, c);
		if (token.compare(PERIOD) == 0) return true;
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

public:
	Lex(ifstream* pFin): pFin(pFin), lookahead(0) {}
	virtual ~Lex() {}

	bool eof() { return pFin->eof(); }

	string readBegin() {
		string token;
		this->readBlanks();
		token = readBeginToken();
		return token;
	}
	string readEnd() {
		string token;
		this->readBlanks();
		token = readEndToken();
		return token;
	}
	string readInt() {
		string token;
		this->readBlanks();
		token = readDigits();
		return token;
	}
	string readFloat() {
		string token;
		this->readBlanks();
		token.append(readDigits());
		token.append(readPeriod());
		token.append(readDigits());
		return token;
	}
	string readString() {
		string token;
		this->readBlanks();
		token = readChars();
		return token;
	}
};

#endif /* LEX_H_ */
