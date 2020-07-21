#include "libs.h"
#include "FlyWeight.h"

Block* FlyWeigth::GetImage(int key, string img)
{
	for (auto el : list)
	{
		if (el->GetId() == key)
		{
			return el;
		}
	}

	Block* b = new Block(key, img);
	list.push_back(b);
	return b;
}