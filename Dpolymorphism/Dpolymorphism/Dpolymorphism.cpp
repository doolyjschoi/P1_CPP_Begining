#include <iostream>
#include <vector>

class GeometricObject
{
public:
	virtual void draw()
	{
		std::cout << "GeometricObject::Draw" << std::endl;
	}
};

class Box : public GeometricObject
{
public:
	void draw()
	{
		std::cout << "Box::Draw" << std::endl;
	}
};

class Circle : public GeometricObject
{
public:
	void draw()
	{
		std::cout << "Circle::Draw" <<  std::endl;
	}
};

int main(void)
{
	//GeometricObject *my_box = new Box;
	//GeometricObject *my_circle = new Circle;
	std::vector< GeometricObject*> go_vector;

	go_vector.push_back(new Box);
	go_vector.push_back(new Circle);

	//for (int i = 0; i < go_vector.size(); i++)
	//	go_vector[i]->draw();
	
	//for (std::vector<GeometricObject*>::iterator itr = go_vector.begin(); itr != go_vector.end(); itr++)
	//	(*itr)->draw();
	
	//for (auto itr = go_vector.begin(); itr != go_vector.end(); itr++)
	//	(*itr)->draw();

	for (auto itr : go_vector)
		(itr)->draw();
	
		//my_box->draw();
	//my_circle->draw();

	return 0;
}