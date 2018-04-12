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
#include "VehicleObject.h"

#include <iostream>
#include <string>
#include <sstream>

TrafficLightEngine::TrafficLightEngine()
	: BaseEngine( 6 )
{ 

	// Number of vehicles
	quantity = 1;
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
	CreateObjectArray(quantity + 6);
	// You MUST set the array entry after the last one that you create to NULL, so that the system knows when to stop.
	// i.e. The LAST entry has to be NULL. The fact that it is NULL is used in order to work out where the end of the array is.
	
	//last entry to NULL
	StoreObjectInArray(quantity + 7, NULL);

	//Generate South vehicles
	sQuantity = 1;
	for (int i = 0; i < sQuantity; i++) {
		SpawnSouthVehicles(i + 6);
	}

	
	StoreObjectInArray(0, new BlockObject1(this));
	StoreObjectInArray(1, new BlockObject2(this));
	StoreObjectInArray(2, new BlockObject3(this));
	StoreObjectInArray(3, new BlockObject4(this));
	StoreObjectInArray(4, new BlockObject5(this));
	StoreObjectInArray(5, new BlockObject6(this));
	
	


	return 0;
}

void TrafficLightEngine::SpawnSouthVehicles(int i)
{
	StoreObjectInArray(i, new VehicleObject(this, 460, 970));
}