#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"
#include "MovementPosition.h"

class VehicleObjectNorth :
	public DisplayableObject
{
public:
	VehicleObjectNorth(TrafficLightEngine *pEngine, int startX, int startY);
	~VehicleObjectNorth(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int XStart;
	int YStart;
	int direction;
	//int individualTime;

private:

	TrafficLightEngine * p_mainEngine;
	MovementPosition m_oMover;

	int m_iMapX;
	int m_iMapY;
	int m_iDir;

};

