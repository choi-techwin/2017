/*
 * Map.cpp
 *
 *  Created on: 2017. 4. 11.
 *      Author: choi.sungwoon
 */

#include "Map.h"
#include <exception>
using namespace std;

template <class KEYTYPE, class VALUETYPE>
VALUETYPE Map<KEYTYPE, VALUETYPE>::getElement(int index) {
	if (index >= this->length || index < 0)
		return 0;

	return this->values[index];
}

template <class KEYTYPE, class VALUETYPE>
VALUETYPE Map<KEYTYPE, VALUETYPE>::find(KEYTYPE key) {
	for (int i=0; i<this->length; i++) {
		if (this->keys[i] == key)
			return values[i];
	}
	return 0;
}

template <class KEYTYPE, class VALUETYPE>
void Map<KEYTYPE, VALUETYPE>::insert(KEYTYPE key, VALUETYPE element) throw() {
	if (this->length == MAXMAPLENGTH)
		throw exception("Map::", "insert", "Overflow", this->length);

	this->keys[this->length] = key;
	this->values[this->length] = element;
	this->length++;
}



