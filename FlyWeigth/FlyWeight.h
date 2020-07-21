#pragma once
#include "libs.h"
#include "Block.h"
class FlyWeigth
{
public:
	static list<Block*> list;

	static Block* GetImage(int key, string img);
};
