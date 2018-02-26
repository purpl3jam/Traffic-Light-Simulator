#pragma once
#include "BaseEngine.h"
class TrafficLightEngine :
	public BaseEngine
{
public:
	TrafficLightEngine();
	~TrafficLightEngine();
	void SetupBackgroundBuffer();

	bool allVisible;
};

