#pragma once

class ValueObject
{
public:
	ValueObject() {}
	virtual ~ValueObject() {}

	virtual int initialize() { return 0; }
};

