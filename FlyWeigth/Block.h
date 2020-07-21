#pragma once
#include "libs.h"

class Block
{
	int id;
	string img;
public:
	Block(int id, string img);

	int GetId();

	void GetImg();
};
