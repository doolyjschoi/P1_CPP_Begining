#pragma once
#include <iostream>
#include "GeometricObject.h"

class Box : public GeometricObject
{
public:
	void draw(); // seperate declaration - definition (header, body)
};