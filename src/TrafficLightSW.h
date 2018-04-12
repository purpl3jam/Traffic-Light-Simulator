#pragma once
#include "DisplayableObject.h"
class TrafficLightSW :
	public DisplayableObject
{
public:
	TrafficLightSW(BaseEngine *pEngine);
	~TrafficLightSW(void);
	void Draw();
};

