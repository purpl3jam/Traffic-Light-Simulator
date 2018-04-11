#pragma once
#include "DisplayableObject.h"
class BlockObject2 :
	public DisplayableObject
{
public:
	BlockObject2(BaseEngine *pEngine);
	~BlockObject2(void);
	void Draw();
};

