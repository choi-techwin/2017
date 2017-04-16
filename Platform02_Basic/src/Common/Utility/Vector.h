/*
 * Vector.h
 *
 *  Created on: 2017. 4. 16.
 *      Author: choi.sungwoon
 */

#ifndef COMMON_UTILITY_VECTOR_H_
#define COMMON_UTILITY_VECTOR_H_

#include <cassert>
#include <iostream>
using namespace std;

#define MAXLENGTH 20

template <class TYPE>
class Vector {
protected:
	TYPE elements[MAXLENGTH];
	int front, rear, length;
public:
	class Iterator {
	private:
		TYPE* pElement;
	public:
		Iterator(TYPE* pELement) : pElement(pELement) {}
		Iterator operator++(int n) { Iterator current = *this; pElement++; return current; }
		TYPE& operator*() { return *pElement; }
		TYPE* operator->() { return pElement; }
		bool operator==(const Iterator& rhs) { return pElement == rhs.pElement; }
		bool operator!=(const Iterator& rhs) { return pElement != rhs.pElement; }
	};
	typedef Iterator iterator;

	Vector(): front(0), rear(0), length(0) {}
	virtual ~Vector() {}
	virtual int initialize() { return 0; }

	Iterator begin() { return Iterator(this->elements + this->front); }
	Iterator end() { return Iterator(this->elements + this->rear); }

	int getLength() { return this->length; }
	bool empty() { return (this->length == 0); }

	virtual void clear() {
		this->front = 0;
		this->rear = 0;
		this->length = 0;
	}

	virtual void enQueue(TYPE element) {
		assert(this->length < MAXLENGTH);

		this->elements[this->rear] = element;
		this->rear++;
		if (this->rear == MAXLENGTH) {
			this->rear = 0;
		}
		this->length++;
	}

	virtual TYPE deQueue() {
		assert(this->length > 0);
		TYPE element;

		element = this->elements[this->front];
		this->front++;
		if (this->front == MAXLENGTH) {
			this->front = 0;
		}
		this->length--;
		return element;
	}
};




#endif /* COMMON_UTILITY_VECTOR_H_ */
