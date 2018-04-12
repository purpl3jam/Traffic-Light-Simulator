#pragma once
#include "DisplayableObject.h"
class TrafficLightSS :
	public DisplayableObject
{
public:
	TrafficLightSS(BaseEngine *pEngine);
	~TrafficLightSS(void);
	void Draw();

	/*int getXPos;
	int getYPos;*/
	//bool green;
};

