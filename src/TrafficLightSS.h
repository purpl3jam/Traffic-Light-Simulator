#pragma once
#include "DisplayableObject.h"
class TrafficLightSS :
	public DisplayableObject
{
public:
	TrafficLightSS(BaseEngine *pEngine, bool light);
	~TrafficLightSS(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int time;

	/*int getXPos;
	int getYPos;*/
	//bool green;
};

