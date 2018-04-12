#pragma once
#include "DisplayableObject.h"
class TrafficLightSE :
	public DisplayableObject
{
public:
	TrafficLightSE(BaseEngine *pEngine);
	~TrafficLightSE(void);
	void Draw();
};

