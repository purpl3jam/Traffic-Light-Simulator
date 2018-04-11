#pragma once
#include "DisplayableObject.h"
class BlockObject3 :
	public DisplayableObject
{
public:
	BlockObject3(BaseEngine *pEngine);
	~BlockObject3(void);
	void Draw();
};

