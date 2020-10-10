#include <iostream>
#include <vector>
#include "GeometricObject.h"
#include "Circle.h"
#include "Box.h"

int main(void)
{
	std::vector< GeometricObject*> go_vector;

	go_vector.push_back(new Circle); 
	go_vector.push_back(new Box);
	
	for (auto itr : go_vector)
		(itr)->draw();

	return 0;
}