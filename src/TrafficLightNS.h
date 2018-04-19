#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightNS :
	public DisplayableObject
{
public:
	TrafficLightNS(TrafficLightEngine *pEngine);
	~TrafficLightNS(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

