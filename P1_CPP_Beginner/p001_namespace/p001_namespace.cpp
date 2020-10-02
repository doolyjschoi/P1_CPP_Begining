#include <stdio.h>
#include <iostream>

namespace AnotherVector
{
	int x;
	int y;
	int z;
}

struct Vector3D
{
	int x; // you can diretly assign default value like int x = 1
	int y;
	int z;

	// Creator
	Vector3D(const int& _x, const int& _y, const int& _z)
		: x(_x), y(_y), z(_z)
	{}

	void printVector() {
		printf("%d %d %d\n", x, y, z);
	}
};

// function overloading (simply remember there is another term - overriding)
// overload << (streaming)
std::ostream& operator << (std::ostream &stream, Vector3D obj)
{
	stream << obj.x << " " << obj.y << " " << obj.z << std::endl;

	return stream;
}

void main(void) {
	AnotherVector::x = 1;


	Vector3D my_vector(4, 5, 6);
	my_vector.printVector();

	std::cout << "Hello, World!" << std::endl;

	std::cout << my_vector.x << " " << my_vector.y 
		      << " " << my_vector.z << std::endl;
}