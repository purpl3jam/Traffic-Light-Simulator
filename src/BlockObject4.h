#pragma once
#include "DisplayableObject.h"
class BlockObject4 :
	public DisplayableObject
{
public:
	BlockObject4(BaseEngine *pEngine);
	~BlockObject4(void);
	void Draw();
};

