/*
 * main.cpp
 *
 *  Created on: 2017. 3. 30.
 *      Author: choi.techwin
 */

#include "Parser.h"
#include "VideoManager.h"

int main() {
	try {
		VideoManager videoManager1;
		VideoManager videoManager2;
		VideoManager videoManager3;

		Parser parser;
		parser.openIn("rsc", "input");
		// read file and build parse tree
		parser.read();
		// load data to a class
		parser.load(videoManager3, "videoManager3");
		parser.load(videoManager1, "videoManager1");
		parser.load(videoManager2, "videoManager2");
		parser.closeIn();

		parser.openOut("rsc", "output");
		// load data to the parser
		parser.store(videoManager1, "videoManager1");
		parser.store(videoManager3, "videoManager3");
		parser.store(videoManager2, "videoManager2");
		// write to the file
		parser.write();
		parser.closeOut();

	} catch (Exception& e) {
		e.what();
	}
}


