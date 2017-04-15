#pragma once


#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cassert>
#include <iostream>
using namespace std;

#define MAXLENGTH 20

template <class TYPE>
class Queue {
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

	Queue(): front(0), rear(0), length(0) {}
	virtual ~Queue() {}
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
		assert(this->length < MAXLENGTH);

		EnterCriticalSection(&this->lock);
		this->elements[this->rear] = element;
		this->rear++;
		if (this->rear == MAXLENGTH) {
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
		if (this->front == MAXLENGTH) {
			this->front = 0;
		}
		this->length--;
		LeaveCriticalSection(&this->lock);

		return element;

	}
};


