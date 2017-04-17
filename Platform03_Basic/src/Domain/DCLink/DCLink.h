#pragma once

#include "../../Framework/Component/EventSource.h"

enum EDCLinkEventType { eDCLINK_0 = __COUNTER__, eDCLINK_1 = __COUNTER__};

class DCLink: public EventSource
{
public:
	DCLink();
	virtual ~DCLink();
	int initialize();

	void generateEvents();
};
