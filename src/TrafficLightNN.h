#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightNN :
	public DisplayableObject
{
public:
	TrafficLightNN(TrafficLightEngine *pEngine);
	~TrafficLightNN(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

private:
	TrafficLightEngine * p_mainEngine;
};

