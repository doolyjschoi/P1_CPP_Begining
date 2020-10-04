#include <iostream>

//step 1: make class
//step 2: make creator
//setp 3: overloading operator(stream operator, additive operator)

//step 1: make class matrix3x3
//step 2: define operator multiply between matrix and vector

class Vector3D
{
public:
	float x, y, z;

	Vector3D(float _x, float _y, float _z) //creator
	{
		x = _x;
		y = _y;
		z = _z;
	}

	Vector3D() // default creator
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3D& operator=(const Vector3D& rhs) // assignment operator overloading 
	{
		this->x = rhs.x;
		this->y = rhs.y;
		this->z = rhs.z;
		return *this; // return the result by reference
	}

	friend Vector3D operator+(Vector3D lhs,	const Vector3D& rhs) // additive operator overloading
	{
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
		return lhs; // return the result by value (uses move constructor)
	}

	friend float operator*(Vector3D vc, const Vector3D& use) // multiply operator(inner product) overloading
	{

		float result = 0.0f;
		result = vc.x * use.x;
		result += vc.y * use.y;
		result += vc.z * use.z;
		return result; // return the result by value (uses move constructor)
	}

	friend std::ostream& operator<< (std::ostream& os, const Vector3D& vc); // operator<< overloading declaration
};

std::ostream& operator<< (std::ostream& os, const Vector3D& vc) // operator<< overloading definition
{
	os << "Vector3D(" << vc.x << ", " << vc.y << ", " << vc.z << ")";

	return os;
}

class Matrix3x3
{
public:
	Vector3D vc_1;
	Vector3D vc_2;
	Vector3D vc_3;

	Matrix3x3(Vector3D _vc1, Vector3D _vc2, Vector3D _vc3) // creator
	{
		vc_1 = _vc1;
		vc_2 = _vc2;
		vc_3 = _vc3;
	}

	Matrix3x3() // default creator
	{
		vc_1 = Vector3D(0, 0, 0);
		vc_2 = Vector3D(0, 0, 0);
		vc_3 = Vector3D(0, 0, 0);
	}
	
	friend Vector3D operator*(Matrix3x3 &matrix, const Vector3D& vector) // multiply operator(inner product) overloading
	{
		Vector3D result;
		result.x = matrix.vc_1 * vector;
		result.y = matrix.vc_2 * vector;
		result.z = matrix.vc_3 * vector;
		//result.x = matrix.vc_1.x * vector.x + matrix.vc_1.y * vector.y + matrix.vc_1.z * vector.z;
		//result.y = matrix.vc_2.x * vector.x + matrix.vc_2.y * vector.y + matrix.vc_2.z * vector.z;
		//result.z = matrix.vc_3.x * vector.x + matrix.vc_3.y * vector.y + matrix.vc_3.z * vector.z;
		return result; // return the Vector3D
	}
};

void main()
{
	Vector3D a(1, 2, 3), b, c;
	b = Vector3D(4, 5, 6);
	c = a + b;

	Matrix3x3 m(a,b,c); //((1,2,3),(4,5,6),(5,7,9))
	Vector3D f = m * b; //This work inner product
	std::cout << a << " + " << b << " = " << c << std::endl << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << b << std::endl << std::endl;
	std::cout << "내적을 구하면" << std::endl;
	std::cout << f << std::endl << std::endl;
}