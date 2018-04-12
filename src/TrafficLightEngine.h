#pragma once
#include "BaseEngine.h"
#include "TileManager.h"
class TrafficLightEngine :
	public BaseEngine
{
public:
	TrafficLightEngine();
	~TrafficLightEngine();
	void SetupBackgroundBuffer();
	int InitialiseObjects();
	void SpawnSouthVehicles(int i);

	int quantity;
	int nQuantity;
	int nEQuantity;
	int sEQuantity;
	int sQuantity;
	int sWQuantity;
	int nWQuantity;
	int startPos;
	bool allVisible;
	int blockI;
	int blockY;

private:
	//TrafficLightEngine m_oTiles;
};

