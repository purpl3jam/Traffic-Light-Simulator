#pragma once
#include "BaseEngine.h"
#include "TileManager.h"
#include <time.h>

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
	void NorthTrafficLights();
	void SouthTrafficLights();

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


	// Time variables
	//int i;
	int sArraySize;
	int tArraySize;
	int arrayTotal;
	int arrayAverage;
	int sTimes[1000];
	int tTimes[10000];
	int sIndividualTime;
	int nIndividualTime;
	int sWIndividualTime;
	int nWIndividualTime;
	int sEIndividualTime;
	int nEIndividualTime;
	int totalTime;
	int firstTime;
	int secondTime;
	int averageTime;

	time_t start, end;
	int elapsed;

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

	double sProportion;
	int sDifference;
	double sMultiplier;

	double nProportion;
	int nDifference;
	double nMultiplier;

private:
	//TrafficLightEngine m_oTiles;
	//VehicleObjectSouth * sVObject;
};

