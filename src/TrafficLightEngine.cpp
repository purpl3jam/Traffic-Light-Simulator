#include "header.h"

#include "BaseEngine.h"

#include "TrafficLightEngine.h"

#include <iostream>
#include <string>
#include <sstream>

TrafficLightEngine::TrafficLightEngine()
	: BaseEngine( 1000 )
{

}


TrafficLightEngine::~TrafficLightEngine()
{
}

void TrafficLightEngine::SetupBackgroundBuffer()
{
	// Set background colour
	FillBackground(0x828b8c);
}