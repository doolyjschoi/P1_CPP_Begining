#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

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
	//AnotherVector::x = 1;


	Vector3D my_vector(4, 5, 6);
	my_vector.printVector();

	std::cout << "Hello, World!" << std::endl;

	//std::cout << my_vector.x << " " << my_vector.y  
	//	      << " " << my_vector.z << std::endl;

	std::cout << my_vector << std::endl;

	// c-style file output
	//FILE *outputfile = fopen("cstyle.txt", "w");
	//fprintf(outputfile, "%d %d %d \n", my_vector.x, my_vector.y, my_vector.z);
	//fclose(outputfile);

	// c++-style file output (textfile output)
	//std::ofstream outputfile("cppstyle.txt");
	//outputfile << my_vector;
	
	using namespace std;
	
	ifstream inpuntfile("paragraph.txt");

	// char string[255];
	string input_string;

	stringstream string_stream;
	string_stream << inpuntfile.rdbuf(); // read the file
	input_string = string_stream.str(); //str holds the contents of the file

	cout << input_string << endl; // you can do anyting with the string!!!

	string typed_string;

	// start time check method
	auto begin = std::chrono::high_resolution_clock::now();

	std::getline(std::cin, typed_string);

	// end time check method
	auto end = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() / 1000.0 << "s" << std::endl;

	std::cout << "Comparison " << typed_string.compare(input_string) << std::endl;
}