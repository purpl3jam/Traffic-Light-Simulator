#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightSE :
	public DisplayableObject
{
public:
	TrafficLightSE(TrafficLightEngine *pEngine);
	~TrafficLightSE(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

