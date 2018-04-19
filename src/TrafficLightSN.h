#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightSN :
	public DisplayableObject
{
public:
	TrafficLightSN(TrafficLightEngine *pEngine);
	~TrafficLightSN(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

