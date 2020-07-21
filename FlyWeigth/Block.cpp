#include "libs.h"
#include "Block.h"

Block::Block(int id, string img)
{
	this->id = id;
	this->img = img;
}

int Block::GetId()
{
	return this->id;
}

void Block::GetImg()
{
	cout << this->img << endl;
}