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
#define BEGIN "{"
#define END "}"
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
		string chars;
		chars.append(1, c);
		if (chars==BEGIN || chars==END) return true;
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

	void readBlanks(ifstream &fin) {
		fin.get(this->lookahead);
		while(isBlank(this->lookahead) && !fin.eof()) {
			fin.get(this->lookahead);
		}
	}
	void readDelimeters(ifstream &fin) {
		fin.get(this->lookahead);
		while(isDelimeter(this->lookahead) && !fin.eof()) {
			fin.get(this->lookahead);
		}
	}
	string readDigits(ifstream &fin) {
		string token;
		while (isDigit(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}
	string readPeriod(ifstream &fin) {
		string token;
		if (isPeriod(this->lookahead) && !fin.eof()) {
			token.append(1, this->lookahead);
			fin.get(this->lookahead);
		}
		return token;
	}


public:
	Lex(): lookahead(0) {}
	virtual ~Lex() {}

	int readInt(ifstream &fin) {
		string token;
		this->readBlanks(fin);
		token = readDigits(fin);
		if (token.empty()) throw new exception();

		stringstream ss;
		ss << token;
		int result;
		ss >> result;
		return result;
	}

	float readFloat(ifstream &fin) {
		string token;
		this->readBlanks(fin);
		token.append(readDigits(fin));
		token.append(readPeriod(fin));
		token.append(readDigits(fin));
		if (token.empty()) throw new exception();

		stringstream ss;
		ss << token;
		float result;
		ss >> result;
		return result;
	}

};

#endif /* LEX_H_ */
