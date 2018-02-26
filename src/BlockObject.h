#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"

class BlockObject :
	public DisplayableObject
{
public:
	BlockObject(TrafficLightEngine* pEngine, int startX, int startY);
	~BlockObject(void);
	void Draw(void);
	int XStart;
	int YStart;

private:

	TrafficLightEngine* p_mainEngine;

};

