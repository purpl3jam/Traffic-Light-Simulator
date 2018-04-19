#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightSW :
	public DisplayableObject
{
public:
	TrafficLightSW(TrafficLightEngine *pEngine);
	~TrafficLightSW(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

