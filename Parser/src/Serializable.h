/*
 * Serializable.h
 *
 *  Created on: 2017. 4. 1.
 *      Author: choi.sungwoon
 */

#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_ "SERIALIZABLE_H_"

#include "Exception.h"
#include "Structure.h"
#include <string>
#include <sstream>
using namespace std;

class Serializable {
private:
	Structure *pStructure;
public:
	Serializable();
	virtual ~Serializable();

	Structure* getStructure();
	void setStructure(Structure* pStructure);
	// get Serializable data from Structures
	virtual void read() = 0;

	void get(Serializable& serializable, string key) throw();
	void get(int& result, string key);
	void get(float& result, string key);
;
	void get(string& result, string key);
	void get(int result[], int length, string key);

	// create Structures from Serializable data
	virtual void write() = 0;
	// load data to child serializable structure
	void set(Serializable& serializable, string key) throw();
	void set(int& value, string key) throw();
	void set(float& value, string key) throw();
	void set(string& value, string key) throw();
};

#endif /* SERIALIZABLE_H_ */
