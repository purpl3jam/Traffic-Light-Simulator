#pragma once
#include "DisplayableObject.h"
class BlockObject1 :
	public DisplayableObject
{
public:
	BlockObject1(BaseEngine* pEngine);
	~BlockObject1(void);
	void Draw();
};

