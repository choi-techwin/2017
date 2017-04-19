/*
 * Collection.h
 *
 *  Created on: 2017. 4. 19.
 *      Author: choi.sungwoon
 */

#ifndef COMMON_UTILITY_COLLECTION_H_
#define COMMON_UTILITY_COLLECTION_H_

#include <iostream>
#include <cassert>
using namespace std;

template <class KEYTYPE, class VALUETYPE>
struct Pair {
	KEYTYPE first;
	VALUETYPE second;
};

template <class KEYTYPE, class VALUETYPE>
Pair<KEYTYPE, VALUETYPE> Make_pair(KEYTYPE keyType, VALUETYPE valueType) {
	Pair<KEYTYPE, VALUETYPE> pair;
	pair.first = keyType;
	pair.second = valueType;
	return pair;
}

template <class KEYTYPE, class VALUETYPE>
class MapIterator {
private:
	Pair<KEYTYPE, VALUETYPE>* pElement;
public:
	MapIterator(Pair<KEYTYPE, VALUETYPE>* pELement) : pElement(pELement) { }
	MapIterator operator++(int n) { MapIterator current = *this; pElement++; return current; }
	Pair<KEYTYPE, VALUETYPE>& operator*() { return *pElement; }
	Pair<KEYTYPE, VALUETYPE>* operator->() { return pElement; }
	bool operator==(const MapIterator& rhs) { return pElement == rhs.pElement; }
	bool operator!=(const MapIterator& rhs) { return pElement != rhs.pElement; }
};

#define MAXMAPLENGTH 20
template <class KEYTYPE, class VALUETYPE>
class Map {
public:
	typedef MapIterator<KEYTYPE, VALUETYPE> Iterator;
private:
	int length;
	Pair<KEYTYPE, VALUETYPE> elements[MAXMAPLENGTH];
public:
	Map(): length(0) {}
	Map(int length): length(length) {}
	virtual ~Map() {}

	Iterator begin() { return Iterator(this->elements); }
	Iterator end() { return Iterator(this->elements + this->length); }

	int getLength() const { return this->length; }
	void clear() { this->length = 0; }

	Pair<KEYTYPE, VALUETYPE>& operator[](int index) const {
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
	void insert(Pair<KEYTYPE, VALUETYPE> element) throw() {
		assert (this->length < MAXMAPLENGTH);

		this->elements[this->length] = element;
		this->length++;
	}

};


#define WIN32_LEAN_AND_MEAN
#include <windows.h>

template <class TYPE>
class ListIterator {
private:
	TYPE* pElement;
public:
	ListIterator(TYPE* pELement) : pElement(pELement) {}
	ListIterator operator++(int n) { ListIterator current = *this; pElement++; return current; }
	TYPE& operator*() { return *pElement; }
	TYPE* operator->() { return pElement; }
	bool operator==(const ListIterator& rhs) { return pElement == rhs.pElement; }
	bool operator!=(const ListIterator& rhs) { return pElement != rhs.pElement; }
};

#define MAXVECTORLENGTH 20
template <class TYPE>
class Vector {
protected:
	TYPE elements[MAXVECTORLENGTH];
	int front, rear, length;
public:
	typedef ListIterator<TYPE> Iterator;

	Vector(): front(0), rear(0), length(0) {}
	virtual ~Vector() {}
	virtual int initialize() { return 0; }

	Iterator begin() { return Iterator(this->elements + this->front); }
	Iterator end() { return Iterator(this->elements + this->rear); }

	int getLength() { return this->length; }
	bool empty() {
		if (length==0) return true;
		return false;
	}

	virtual void clear() {
		this->front = 0;
		this->rear = 0;
		this->length = 0;
	}

	virtual void push_back(TYPE element) {
		assert(this->length < MAXVECTORLENGTH);

		this->elements[this->rear] = element;
		this->rear++;
		if (this->rear == MAXVECTORLENGTH) {
			this->rear = 0;
		}
		this->length++;
	}
};


#define MAXQUEUELENGTH 20
template <class TYPE>
class Queue {
protected:
	TYPE elements[MAXQUEUELENGTH];
	int front, rear, length;
public:
	typedef ListIterator<TYPE> Iterator;

	Queue(): front(0), rear(0), length(0) {}
	virtual ~Queue() {}
	virtual int initialize() { return 0; }

	Iterator begin() { return Iterator(this->elements + this->front); }
	Iterator end() { return Iterator(this->elements + this->rear); }

	int getLength() { return this->length; }
	bool empty() {
		if (length==0) return true;
		return false;
	}

	virtual void clear() {
		this->front = 0;
		this->rear = 0;
		this->length = 0;
	}

	virtual void enQueue(TYPE element) {
		assert(this->length < MAXQUEUELENGTH);

		this->elements[this->rear] = element;
		this->rear++;
		if (this->rear == MAXQUEUELENGTH) {
			this->rear = 0;
		}
		this->length++;
	}

	virtual TYPE deQueue() {
		assert(this->length > 0);
		TYPE element;

		element = this->elements[this->front];
		this->front++;
		if (this->front == MAXQUEUELENGTH) {
			this->front = 0;
		}
		this->length--;
		return element;
	}
};


template <class TYPE>
class SafeQueue: public Queue<TYPE> {
private:
	CRITICAL_SECTION lock;
public:
	SafeQueue() {
		InitializeCriticalSection(&this->lock);
	}
	virtual ~SafeQueue() {}
	virtual int initialize() { return 0; }

	virtual void clear() {
		EnterCriticalSection(&this->lock);
		this->front = 0;
		this->rear = 0;
		this->length = 0;
		LeaveCriticalSection(&this->lock);
	}

	virtual void enQueue(TYPE element) {
		assert(this->length < MAXQUEUELENGTH);

		EnterCriticalSection(&this->lock);
		this->elements[this->rear] = element;
		this->rear++;
		if (this->rear == MAXQUEUELENGTH) {
			this->rear = 0;
		}
		this->length++;
		LeaveCriticalSection(&this->lock);

	}

	virtual TYPE deQueue() {
		assert(this->length > 0);
		TYPE element;

		EnterCriticalSection(&this->lock);
		element = this->elements[this->front];
		this->front++;
		if (this->front == MAXQUEUELENGTH) {
			this->front = 0;
		}
		this->length--;
		LeaveCriticalSection(&this->lock);

		return element;

	}
};

#endif /* COMMON_UTILITY_COLLECTION_H_ */
