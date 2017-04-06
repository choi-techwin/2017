#pragma once

class ValueObject
{
private:
	void *pValue;

public:
	ValueObject() { this->pValue = 0; }
	virtual ~ValueObject() {}

	virtual int initialize() { return 0; }
	virtual void setValue(void* pValue) { this->pValue = pValue; }
	virtual void* getValue() { return this->pValue; }
};

