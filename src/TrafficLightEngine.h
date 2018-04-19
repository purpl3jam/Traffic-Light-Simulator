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
	void DrawStringsOnTop();
	void MachineLearningAlgorithm();
	void RedCounting();

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

	int sIndividualTime;
	int nIndividualTime;
	int sWIndividualTime;
	int nWIndividualTime;
	int sEIndividualTime;
	int nEIndividualTime;
	int totalTime;

	// Traffic light variables
	bool mLAlgorithmOn;
	int sSRed;
	int nSRed;
	int sNRed;
	int nNRed;
	int sWRed;
	int nWRed;
	int sERed;
	int nERed;

private:
	//TrafficLightEngine m_oTiles;
	//VehicleObjectSouth * sVObject;
};

