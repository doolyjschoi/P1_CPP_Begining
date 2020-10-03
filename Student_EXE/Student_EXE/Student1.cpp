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
	Vector3D& operator=(const Vector3D& rhs) // compound assignment (does not need to be a member,
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		return *this; // return the result by reference
	}
	// passing lhs by value helps optimize chained a+b+c otherwise, both parameters may be const references
	friend Vector3D operator+(Vector3D lhs,	const Vector3D& rhs) 
	{
		lhs.x += rhs.x; // reuse compound assignment
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs; // return the result by value (uses move constructor)
	}

	friend std::ostream& operator<< (std::ostream& os, const Vector3D& vc);
};

std::ostream& operator<< (std::ostream& os, const Vector3D& vc)
{
	os << "Vector3D(" << vc.x << ", " << vc.y << ", " << vc.z << ")";

	return os;
}

void main()
{
	Vector3D a(1, 2, 3), b, c;
	b = Vector3D(4, 5, 6);
	c = a + b;

	std::cout << a << " + " << b << " = "  << c << std::endl;
}