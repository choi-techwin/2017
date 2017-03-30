/*
 * Lex.h
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#ifndef LEX_H_
#define LEX_H_

#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#define BLANK " \t\n\r"
#define BEGIN '{'
#define END '}'
#define PERIOD '.'

class Lex {
private:
	char lookahead;

	bool isBlank(char c) {
		if (string(BLANK).find(c) != string::npos) return true;
		return false;
	}
	bool isDelimeter(char c) {
		if (isBlank(c)) return true;
		if (c==BEGIN || c==END) return true;
		return false;
	}
	bool isDigit(char c) {
		if (c>='0' && c<='9') return true;
		return false;
	}
	bool isPeriod(char c) {
		if (c == PERIOD) return true;
		return false;
	}

	void readBlank(ifstream &fin) {
		fin.get(this->lookahead);
		while(isBlank(this->lookahead) && !fin.eof()) {
			if (fin.eof()) return;
			fin.get(this->lookahead);
		}
	}
	void readDelimeter(ifstream &fin) {
		fin.get(this->lookahead);
		while(isDelimeter(this->lookahead) && !fin.eof()) {
			if (fin.eof()) return;
			fin.get(this->lookahead);
		}
	}
	string readDigit(ifstream &fin) {
		string digits;
		fin.get(this->lookahead);
		while(isDigit(this->lookahead)) {
			if (fin.eof()) return digits;
			fin.get(this->lookahead);
		}

	}

public:
	Lex(): lookahead(0) {}
	virtual ~Lex() {}

	int readInt(ifstream &fin) {
		string token;
		this->readBlank(fin);
		while (isDigit(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		if (token.empty()) throw new exception();

		stringstream ss;
		ss << token;
		int result;
		ss >> result;
		return result;
	}

	int readFloat(ifstream &fin) {
		string token;
		this->readBlank(fin);
		while (isDigit(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		if (token.empty()) throw exception;

		stringstream ss;
		ss << token;
		int result;
		ss >> result;
		return result;
	}

};

#endif /* LEX_H_ */
