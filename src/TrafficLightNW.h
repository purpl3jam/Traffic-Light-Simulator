#pragma once
#include "DisplayableObject.h"
class TrafficLightNW :
	public DisplayableObject
{
public:
	TrafficLightNW(BaseEngine *pEngine);
	~TrafficLightNW(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;
};

