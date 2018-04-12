#pragma once
#include "DisplayableObject.h"
#include "TrafficLightSS.h"
#include "TrafficLightEngine.h"
#include "MovementPosition.h"

//class TrafficLightEngine;

class VehicleObjectSouth :
	public DisplayableObject
{
public:
	VehicleObjectSouth(BaseEngine *pEngine, int startX, int startY);
	~VehicleObjectSouth(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	int XStart;
	int YStart;
	int direction;

	//TrafficLightSS* TLSS;

private:

	TrafficLightEngine* p_mainEngine;
	MovementPosition m_oMover;

	int m_iMapX;
	int m_iMapY;
	int m_iDir;

};

