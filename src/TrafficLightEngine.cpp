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
#include <stdexcept>
#include <stdio.h>
#include <time.h>
#include <ctime>

using namespace std;

#define BASE_OBJECTS 16
//#define TIME_OF_DAY "Morning"

TrafficLightEngine::TrafficLightEngine()


	: BaseEngine( BASE_OBJECTS )
{ 

	// Number of vehicles
	sQuantity = 40;
	nQuantity = 40;
	sWQuantity = 5;
	nWQuantity = 5;
	sEQuantity = 5;
	nEQuantity = 5;
	quantity = sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity + nEQuantity;
	baseObjects = BASE_OBJECTS;

	// Morning == 1
	// Evening == 2
	// Midday == 3
	timeOfDay = 2;

	totalTime = 0;
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
	for (int i = 0; i < sQuantity; i++) {
		SpawnSouthVehicles(i + BASE_OBJECTS);
	}

	//Generate North vehicles
	for (int i = sQuantity; i < (sQuantity + nQuantity); i++) {
		//cout << i;
		SpawnNorthVehicles(i + BASE_OBJECTS);
	}

	//Generate SouthWest vehicles
	for (int i = (sQuantity + nQuantity); i < (sQuantity + nQuantity + sWQuantity); i++) {
		SpawnSouthWestVehicles(i + BASE_OBJECTS);
	}

	//Generate NorthWest vehicles
	for (int i = (sQuantity + nQuantity + sWQuantity); i < (sQuantity + nQuantity + sWQuantity + nWQuantity); i++) {
		SpawnNorthWestVehicles(i + BASE_OBJECTS);
	}

	//Generate SouthEast vehicles
	for (int i = (sQuantity + nQuantity + sWQuantity + nWQuantity); i < (sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity); i++) {
		SpawnSouthEastVehicles(i + BASE_OBJECTS);
	}

	//Generate NorthEast vehicles
	for (int i = (sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity); i < (sQuantity + nQuantity + sWQuantity + nWQuantity + sEQuantity + nEQuantity); i++) {
		SpawnNorthEastVehicles(i + BASE_OBJECTS);
	}

	return 0;
}

void TrafficLightEngine::SpawnSouthVehicles(int i)
{
	if (timeOfDay == 1) {
		startPos = rand() % 3000 + 301;
	}
	else if (timeOfDay == 2) {
		startPos = rand() % 30000 + 301;
	}
	else if (timeOfDay == 3) {
		startPos = rand() % 15000 + 301;
	}
	StoreObjectInArray(i, new VehicleObjectSouth(this, 0 - startPos, 970));
}

void TrafficLightEngine::SpawnNorthVehicles(int i)
{
	if (timeOfDay == 1) {
		startPos = rand() % 30000 + 1301;
	}
	else if (timeOfDay == 2) {
		startPos = rand() % 3000 + 1301;
	}
	else if (startPos == 3) {
		startPos = rand() % 15000 + 1301;
	}
	StoreObjectInArray(i, new VehicleObjectNorth(this, 0 + startPos, 0));
}

void TrafficLightEngine::SpawnSouthWestVehicles(int i)
{
	if (timeOfDay == 1) {
		startPos = rand() % 3000 + 301;
	}
	else if (timeOfDay == 2) {
		startPos = rand() % 3000 + 301;
	}
	else if (startPos == 3) {
		startPos = rand() % 10000 + 301;
	}
	StoreObjectInArray(i, new VehicleObjectSouthWest(this, 0 - startPos, 710));
}

void TrafficLightEngine::SpawnNorthWestVehicles(int i)
{
	if (timeOfDay == 1) {
		startPos = rand() % 3000 + 301;
	}
	else if (timeOfDay == 2) {
		startPos = rand() % 3000 + 301;
	}
	else if (startPos == 3) {
		startPos = rand() % 10000 + 301;
	}
	StoreObjectInArray(i, new VehicleObjectNorthWest(this, 0 - startPos, 210));
}

void TrafficLightEngine::SpawnSouthEastVehicles(int i)
{
	if (timeOfDay == 1) {
		startPos = rand() % 3000 + 1301;
	}
	else if (timeOfDay == 2) {
		startPos = rand() % 3000 + 1301;
	}
	else if (startPos == 3) {
		startPos = rand() % 10000 + 1301;
	}
	StoreObjectInArray(i, new VehicleObjectSouthEast(this, 0 + startPos, 760));
}

void TrafficLightEngine::SpawnNorthEastVehicles(int i)
{
	if (timeOfDay == 1) {
		startPos = rand() % 3000 + 1301;
	}
	else if (timeOfDay == 2) {
		startPos = rand() % 3000 + 1301;
	}
	else if (startPos == 3) {
		startPos = rand() % 10000 + 1301;
	}
	StoreObjectInArray(i, new VehicleObjectNorthEast(this, 0 + startPos, 260));
}

void TrafficLightEngine::DrawStringsOnTop()
{
	/********** Draw South times **********/
	DrawScreenString(120, 970, "Avg South Wait:", 0x000000, NULL);

	sIndividualTime = 0;
	// Get wait times for all South vehicles
	DisplayableObject* vSObject;
	for (int iObjectId = baseObjects; (vSObject = GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (vSObject->sVehicleObject == true) {

			sIndividualTime = sIndividualTime + vSObject->individualTime;
		}
	}
	// Get average
	sIndividualTime = sIndividualTime / sQuantity;

	std::string s = std::to_string(sIndividualTime);
	char const* schar = s.c_str();
	DrawScreenString(350, 970, schar, 0xe87410, NULL);



	/********** Draw North times **********/
	DrawScreenString(550, 0, "Avg North Wait:", 0x000000, NULL);

	nIndividualTime = 0;
	// Get wait times for all North vehicles
	DisplayableObject* vNObject;
	for (int iObjectId = baseObjects; (vNObject = GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (vNObject->nVehicleObject == true) {
			nIndividualTime = nIndividualTime + vNObject->individualTime;
		}
	}
	// Get average
	nIndividualTime = nIndividualTime / nQuantity;

	std::string n = std::to_string(nIndividualTime);
	char const* nchar = n.c_str();
	DrawScreenString(780, 0,nchar, 0xe87410, NULL);



	/********** Draw South West times **********/
	DrawScreenString(0, 670, "Avg SW Wait:", 0x000000, NULL);

	sWIndividualTime = 0;
	// Get wait times for all South West vehicles
	DisplayableObject* vSWObject;
	for (int iObjectId = baseObjects; (vSWObject = GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (vSWObject->sWVehicleObject == true) {

			sWIndividualTime = sWIndividualTime + vSWObject->individualTime;
		}
	}
	// Get average
	sWIndividualTime = sWIndividualTime / sWQuantity;

	std::string sw = std::to_string(sWIndividualTime);
	char const* swchar = sw.c_str();
	DrawScreenString(190, 670, swchar, 0xe87410, NULL);



	/********** Draw North West times **********/
	DrawScreenString(0, 170, "Avg NW Wait:", 0x000000, NULL);

	nWIndividualTime = 0;
	// Get wait times for all North West vehicles
	DisplayableObject* vNWObject;
	for (int iObjectId = baseObjects; (vNWObject = GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (vNWObject->nWVehicleObject == true) {
			nWIndividualTime = nWIndividualTime + vNWObject->individualTime;
		}
	}
	// Get average
	nWIndividualTime = nWIndividualTime / nWQuantity;

	std::string nw = std::to_string(nWIndividualTime);
	char const* nwchar = nw.c_str();
	DrawScreenString(190, 170, nwchar, 0xe87410, NULL);



	/********** Draw South East times **********/
	DrawScreenString(720, 800, "Avg SE Wait:", 0x000000, NULL);

	sEIndividualTime = 0;
	// Get wait times for all South East vehicles
	DisplayableObject* vSEObject;
	for (int iObjectId = baseObjects; (vSEObject = GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (vSEObject->sEVehicleObject == true) {

			sEIndividualTime = sEIndividualTime + vSEObject->individualTime;
		}
	}
	// Get average
	sEIndividualTime = sEIndividualTime / sEQuantity;

	std::string se = std::to_string(sEIndividualTime);
	char const* sechar = se.c_str();
	DrawScreenString(910, 800, sechar, 0xe87410, NULL);



	/********** Draw North East times **********/
	DrawScreenString(720, 300, "Avg NE Wait:", 0x000000, NULL);

	nEIndividualTime = 0;
	// Get wait times for all North East vehicles
	DisplayableObject* vNEObject;
	for (int iObjectId = baseObjects; (vNEObject = GetDisplayableObject(iObjectId)) != NULL;
		iObjectId++)
	{
		if (vNEObject->nEVehicleObject == true) {
			nEIndividualTime = nEIndividualTime + vNEObject->individualTime;
		}
	}
	// Get average
	nEIndividualTime = nEIndividualTime / nEQuantity;

	std::string ne = std::to_string(nEIndividualTime);
	char const* nechar = ne.c_str();
	DrawScreenString(910, 300, nechar, 0xe87410, NULL);



	/********** Display total wait time **********/
	DrawScreenString(60, 60, "Avg Total Wait:", 0x000000, NULL);

	//cout << sIndividualTime;
	//cout << "/";

	totalTime = 0;
	totalTime = ((sIndividualTime * sQuantity)  + (nIndividualTime * nQuantity) + (sWIndividualTime * sWQuantity) + (nWIndividualTime * nWQuantity) + (sEIndividualTime * sEQuantity) + (nEIndividualTime * nEQuantity)) / (0.6 * quantity);
	
	//cout << (sIndividualTime + nIndividualTime + sWIndividualTime + nWIndividualTime + sEIndividualTime + nEIndividualTime);
	//cout << "/";

	std::string sT = std::to_string(totalTime);
	char const* tchar = sT.c_str();
	DrawScreenString(290, 60, tchar, 0x22ad0f, NULL);



	/********** Display time **********/
	/*DrawScreenString(600, 940, "Time(s):", 0x000000, NULL);
	time_t seconds;
	seconds = time(NULL);
	char* dt = ctime(&seconds);
	DrawScreenString(700, 940, dt, 0x22ad0f, NULL);*/
}