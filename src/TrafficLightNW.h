#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightNW :
	public DisplayableObject
{
public:
	TrafficLightNW(TrafficLightEngine *pEngine);
	~TrafficLightNW(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

