#pragma once
#include "DisplayableObject.h"
class TrafficLightNN :
	public DisplayableObject
{
public:
	TrafficLightNN(BaseEngine *pEngine);
	~TrafficLightNN(void);
	void Draw();
};

