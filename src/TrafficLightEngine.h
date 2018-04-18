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
	void SpawnNorthVehicles(int i);
	void SpawnSouthWestVehicles(int i);
	void SpawnNorthWestVehicles(int i);
	void SpawnSouthEastVehicles(int i);
	void SpawnNorthEastVehicles(int i);
	void DrawIndividualWaitTime(int time, int x, int y);
	void DrawStringsOnTop();

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
	int baseObjects;
	int timeOfDay;
	int individualTime;
	int totalTime;

	// Traffic light variables
	bool verticle;

private:
	//TrafficLightEngine m_oTiles;
	//VehicleObjectSouth * sVObject;
};

