#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class TrafficLightSS :
	public DisplayableObject
{
public:
	TrafficLightSS(TrafficLightEngine *pEngine);
	~TrafficLightSS(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

	/*int getXPos;
	int getYPos;*/
	//bool green;

private:
	TrafficLightEngine * p_mainEngine;
};

