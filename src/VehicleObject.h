#pragma once
#include "DisplayableObject.h"
class VehicleObject :
	public DisplayableObject
{
public:
	VehicleObject(BaseEngine *pEngine, int startX, int startY);
	~VehicleObject(void);
	void Draw();
	void DoUpdate(int iCurrentTime);
	int XStart;
	int YStart;
	int direction;
};

