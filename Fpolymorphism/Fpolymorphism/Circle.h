#pragma once
#include <iostream>
#include "GeometricObject.h"

class Circle : public GeometricObject
{
public:
	void draw()
	{
		// draw a circle
		std::cout << "Circle::Draw" << std::endl;
	}
};
