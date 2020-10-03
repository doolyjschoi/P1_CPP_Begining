#include <iostream>

//step 1: make class
//step 2: make creator
//setp 3: overloading operator(stream operator, additive operator)

class Vector3D
{
public:
	float x, y, z;

	//creator
	Vector3D(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	// default creatro
	Vector3D()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	friend std::ostream& operator<< (std::ostream& out, const Vector3D& vector3D);
};

std::ostream& operator<< (std::ostream& out, const Vector3D& vector3D)
{
	out << "Vector3D(" << vector3D.x << ", " << vector3D.y << ", " << vector3D.z << ")";

	return out;
}

void main()
{
	Vector3D a(1, 2, 3), b, c;
	b = Vector3D(4, 5, 6);
	//c = a + b;

	std::cout << c << std::endl;
}