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
		Parser parser("rsc", "videoManager");
		parser.read();

		parser.write();
	} catch (exception& e) {
		cout << e.what();
	}
}


