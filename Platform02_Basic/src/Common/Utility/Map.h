/*
 * Map.h
 *
 *  Created on: 2017. 4. 9.
 *      Author: choi.sungwoon
 */

#ifndef MAP_H_
#define MAP_H_

#define MAXMAPLENGTH 100

template <class KEYTYPE, class VALUETYPE>
class Map {
private:
	int length;
	KEYTYPE keys[MAXMAPLENGTH];
	VALUETYPE values[MAXMAPLENGTH];
public:
	Map() { this->length = 0; }
	virtual ~Map() {}

	int getLength() { return this->length; }
	void clear() { this->length = 0; }

	VALUETYPE getElement(int index);
	VALUETYPE find(KEYTYPE key);
	void insert(KEYTYPE key, VALUETYPE values) throw();
};


#endif /* MAP_H_ */
