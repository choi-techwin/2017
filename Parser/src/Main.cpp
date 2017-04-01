/*
 * main.cpp
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#include "Parser.h"
#include "VideoManager.h"
#include "Exception.h"

int main() {
	try {
		string pathName = "rsc";
		string fileName = "data";

		Parser parser;
		parser.read(pathName, fileName);
		VideoManager videoManager("videoManager");
		parser >> videoManager;

		parser.write();
		videoManager.write();

	} catch (Exception& e) {
		e.what();
	}
}


