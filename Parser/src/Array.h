/*
 * Array.h
 *
 *  Created on: 2017. 4. 6.
 *      Author: choi.sungwoon
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include "Structure.h"

class Array: public Structure {
public:
	Array();
	virtual ~Array();

	bool isArray();

	void read(Lex& lex, string key) throw();
	void write(Lex& lex) throw();
};

#endif /* ARRAY_H_ */
