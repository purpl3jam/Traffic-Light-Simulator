#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"
#include "MovementPosition.h"

class VehicleObjectSouthWest :
	public DisplayableObject
{
public:
	VehicleObjectSouthWest(TrafficLightEngine *pEngine, int startX, int startY);
	~VehicleObjectSouthWest(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int XStart;
	int YStart;
	int direction;
	bool side = true;
	//int individualTime;

private:

	TrafficLightEngine * p_mainEngine;
	MovementPosition m_oMover;

	int m_iMapX;
	int m_iMapY;
	int m_iDir;

};

