/*
 * main.cpp
 *
 *  Created on: 2017. 3. 23.
 *      Author: choi.techwin
 */

#include "setting.h"

int main() {
	Parser parser;
	parser.read("videoManager");

	VideoManager videoManager;
	videoManager.write(&parser, "videoManager");
	videoManager.get(&parser, "videoManager");
}


