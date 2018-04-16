#pragma once
#include "DisplayableObject.h"
class TrafficLightNS :
	public DisplayableObject
{
public:
	TrafficLightNS(BaseEngine *pEngine);
	~TrafficLightNS(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;
};

