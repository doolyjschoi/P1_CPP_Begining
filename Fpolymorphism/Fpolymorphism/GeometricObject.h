#pragma once
#include <string>
class GeometricObject
{
public:
	//virtual void draw() = 0;
	virtual void draw()
	{
		// default draw function for all children
	}
	static GeometricObject* getGeometricObject(const std::string& name);

};