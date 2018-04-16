#pragma once
#include "DisplayableObject.h"
class TrafficLightNE :
	public DisplayableObject
{
public:
	TrafficLightNE(BaseEngine *pEngine);
	~TrafficLightNE(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;
};

