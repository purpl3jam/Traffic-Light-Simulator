#pragma once
#include "DisplayableObject.h"
#include "TrafficLightEngine.h"
#include "MovementPosition.h"

class VehicleObjectNorthWest :
	public DisplayableObject
{
public:
	VehicleObjectNorthWest(TrafficLightEngine *pEngine, int startX, int startY);
	~VehicleObjectNorthWest(void);
	void Draw();
	void DoUpdate(int iCurrentTime);

	int XStart;
	int YStart;
	int direction;
	bool side = true;

private:

	TrafficLightEngine * p_mainEngine;
	MovementPosition m_oMover;

	int m_iMapX;
	int m_iMapY;
	int m_iDir;

};

