#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightNE :
	public DisplayableObject
{
public:
	TrafficLightNE(TrafficLightEngine *pEngine);
	~TrafficLightNE(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

