#include "header.h"
#include "templates.h"

#include "BaseEngine.h"
#include "DisplayableObject.h"

#include "TrafficLightEngine.h"
#include "BlockObject1.h"
#include "BlockObject2.h"
#include "BlockObject3.h"
#include "BlockObject4.h"
#include "BlockObject5.h"
#include "BlockObject6.h"
#include "BlockObject7.h"
#include "BlockObject8.h"

#include "TrafficLightSS.h"
#include "TrafficLightNS.h"
#include "TrafficLightNN.h"
#include "TrafficLightSN.h"
#include "TrafficLightSW.h"
#include "TrafficLightNW.h"
#include "TrafficLightSE.h"
#include "TrafficLightNE.h"

#include "VehicleObjectSouth.h"
#include "VehicleObjectNorth.h"
#include "VehicleObjectSouthWest.h"
#include "VehicleObjectNorthWest.h"
#include "VehicleObjectSouthEast.h"
#include "VehicleObjectNorthEast.h"

#include <iostream>
#include <string>
#include <sstream>

#define BASE_OBJECTS 16
#define TIME_OF_DAY "Morning"

TrafficLightEngine::TrafficLightEngine()
	: BaseEngine( BASE_OBJECTS )
{ 

	// Number of vehicles
	quantity = 100;
}


TrafficLightEngine::~TrafficLightEngine()
{

}

void TrafficLightEngine::SetupBackgroundBuffer()
{
	// Set background colour
	FillBackground(0x828b8c);

	/*// Specify how many tiles wide and high
	m_oTiles.SetSize(15, 11);
	// Set up the tiles
	for (int x = 0; x < 15; x++)
		for (int y = 0; y < 11; y++)
			m_oTiles.SetValue(x, y, rand() % 31);
	// Specify the screen x,y of top left corner
	m_oTiles.SetBaseTilesPositionOnScreen(25, 40);
	// Tell it to draw tiles from x1,y1 to x2,y2 in tile array,
	// to the background of this screen
	m_oTiles.DrawAllTiles(this, this->GetBackground(), 0, 0, 14, 10);*/
}

int TrafficLightEngine::InitialiseObjects(void)
{
	// Record the fact that we are about to change the array - so it doesn't get used elsewhere without reloading it
	DrawableObjectsChanged();
	// Destroy any existing objects
	DestroyOldObjects();
	// Creates an array to store the objects
	// Needs to have room for the NULL at the end
	CreateObjectArray(quantity + BASE_OBJECTS);
	// You MUST set the array entry after the last one that you create to NULL, so that the system knows when to stop.
	// i.e. The LAST entry has to be NULL. The fact that it is NULL is used in order to work out where the end of the array is.
	
	//last entry to NULL
	StoreObjectInArray(quantity + BASE_OBJECTS, NULL);

	//Generate fixed objects
	StoreObjectInArray(0, new BlockObject1(this));
	StoreObjectInArray(1, new BlockObject2(this));
	StoreObjectInArray(2, new BlockObject3(this));
	StoreObjectInArray(3, new BlockObject4(this));
	StoreObjectInArray(4, new BlockObject5(this));
	StoreObjectInArray(5, new BlockObject6(this));
	StoreObjectInArray(6, new BlockObject7(this));
	StoreObjectInArray(7, new BlockObject8(this));



	// Generate traffic lights
	StoreObjectInArray(8, new TrafficLightSS(this));
	StoreObjectInArray(9, new TrafficLightNS(this));
	StoreObjectInArray(10, new TrafficLightNN(this));
	StoreObjectInArray(11, new TrafficLightSN(this));
	StoreObjectInArray(12, new TrafficLightSW(this));
	StoreObjectInArray(13, new TrafficLightNW(this));
	StoreObjectInArray(14, new TrafficLightSE(this));
	StoreObjectInArray(15, new TrafficLightNE(this));

	//Generate South vehicles
	sQuantity = 40;
	for (int i = 0; i < sQuantity; i++) {
		SpawnSouthVehicles(i + BASE_OBJECTS);
	}

	//Generate North vehicles
	nQuantity = 40;
	for (int i = sQuantity; i < (sQuantity + nQuantity); i++) {
		SpawnNorthVehicles(i + BASE_OBJECTS);
	}

	//Generate SouthWest vehicles
	sWQuantity = 5;
	for (int i = (sQuantity + nQuantity); i < (sQuantity + nQuantity + sWQuantity); i++) {
		SpawnSouthWestVehicles(i + BASE_OBJECTS);
	}

	//Generate NorthWest vehicles
	nWQuantity = 5;
	for (int i = (sQuantity + nQuantity + sWQuantity); i < (sQuantity + nQuantity + sWQuantity + nWQuantity); i++) {
		SpawnNorthWestVehicles(i + BASE_OBJECTS);
	}

	//Generate SouthEast vehicles
	sEQuantity = 5;
	for (int i = (sQuantity + nQuantity + sWQuantity + nWQuantity); i < (sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity); i++) {
		SpawnSouthEastVehicles(i + BASE_OBJECTS);
	}

	//Generate NorthEast vehicles
	nEQuantity = 5;
	for (int i = (sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity); i < (sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity + nEQuantity); i++) {
		SpawnNorthEastVehicles(i + BASE_OBJECTS);
	}

	return 0;
}

void TrafficLightEngine::SpawnSouthVehicles(int i)
{
	startPos = rand() % 30000 + 1;
	StoreObjectInArray(i, new VehicleObjectSouth(this, 0 - startPos, 970));
}

void TrafficLightEngine::SpawnNorthVehicles(int i)
{
	StoreObjectInArray(i, new VehicleObjectNorth(this, 510, 0));
}

void TrafficLightEngine::SpawnSouthWestVehicles(int i)
{
	StoreObjectInArray(i, new VehicleObjectSouthWest(this, 0, 710));
}

void TrafficLightEngine::SpawnNorthWestVehicles(int i)
{
	StoreObjectInArray(i, new VehicleObjectNorthWest(this, 0, 210));
}

void TrafficLightEngine::SpawnSouthEastVehicles(int i)
{
	StoreObjectInArray(i, new VehicleObjectSouthEast(this, 970, 760));
}

void TrafficLightEngine::SpawnNorthEastVehicles(int i)
{
	StoreObjectInArray(i, new VehicleObjectNorthEast(this, 970, 260));
}

/*void TrafficLightEngine::DrawIndividualWaitTime(int time, int x, int y)
{
	CopyBackgroundPixels(350, 850, 50, 30);
	std::string s = std::to_string(time);
	char const* pchar = s.c_str();
	DrawScreenString(350, 850, "test", 0xaf0e0e, NULL);
}*/

//void TrafficLightEngine::DrawStrings(/*int time*/ int x, int y)
//{
	//CopyBackgroundPixels(0/*X*/, 0/*Y*/, GetScreenWidth(), 30/*Height*/);
	//std::string s = std::to_string(time);
	//char const* pchar = s.c_str();
	//DrawScreenString(150, 850, "test", 0xaf0e0e, NULL);
//}