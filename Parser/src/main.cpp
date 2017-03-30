/*
 * main.cpp
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#include "Parser.h"

#include <iostream>
#include <exception>
using namespace std;

int main() {
	try {
		Parser parser;
		parser.open("rsc/data.txt");
		int result;
		result = parser.readInt();
		cout << result << endl;
		result = parser.readInt();
		cout << result << endl;
		result = parser.readInt();
		cout << result << endl;
		parser.close();
	} catch (exception& e) {
		cout << e.what();
	}
}


