#pragma once
#include "DisplayableObject.h"
class TrafficLightSN :
	public DisplayableObject
{
public:
	TrafficLightSN(BaseEngine *pEngine);
	~TrafficLightSN(void);
	void Draw();
};

