#pragma once
#include "DisplayableObject.h"
class BlockObject5 :
	public DisplayableObject
{
public:
	BlockObject5(BaseEngine *pEngine);
	~BlockObject5(void);
	void Draw();
};

