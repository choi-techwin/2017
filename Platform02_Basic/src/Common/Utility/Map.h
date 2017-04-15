/*
 * Map.h
 *
 *  Created on: 2017. 4. 9.
 *      Author: choi.sungwoon
 */

#ifndef MAP_H_
#define MAP_H_

#include <cassert>
#include <utility>
using namespace std;

#define MAXMAPLENGTH 20

template <class KEYTYPE, class VALUETYPE>
class Map {
public:
	typedef pair<KEYTYPE, VALUETYPE> Element;

	class Iterator {
	private:
		Element* pElement;
	public:
		Iterator(Element* pELement) : pElement(pELement) { }
		Iterator operator++(int n) { Iterator current = *this; pElement++; return current; }
		Element& operator*() { return *pElement; }
		Element* operator->() { return pElement; }
		bool operator==(const Iterator& rhs) { return pElement == rhs.pElement; }
		bool operator!=(const Iterator& rhs) { return pElement != rhs.pElement; }
	};
	typedef Iterator iterator;
private:
	int length;
	Element elements[MAXMAPLENGTH];
public:
	Map(): length(0) {}
	Map(int length): length(length) {}
	virtual ~Map() {}

	Iterator begin() { return Iterator(this->elements); }
	Iterator end() { return Iterator(this->elements + this->length); }

	int getLength() const { return this->length; }
	void clear() { this->length = 0; }

	Element& operator[](int index) const {
		assert(index < this->length);
		return this->elements[index];
	}

	Iterator find(KEYTYPE key) {
		for (int i=0; i<this->length; i++) {
			if (this->elements[i].first == key)
				return Iterator(&(this->elements[i]));
		}
		return Iterator(elements+this->length);

	}

	void insert(Element element) throw() {
		assert (this->length < MAXMAPLENGTH);

		this->elements[this->length] = element;
		this->length++;
	}

};

#endif /* MAP_H_ */
