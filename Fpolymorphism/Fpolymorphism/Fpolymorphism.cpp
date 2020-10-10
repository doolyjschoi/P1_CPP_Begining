#include <iostream>
#include "Box.h"
#include "Circle.h"
//#include "GeometricObject.h"
#include <vector> // array와 거의 비슷한 개념
int main()
{
    std::cout << "Hello World!\n";

    //GeometricObject** object_list = new GeometricObject * [10];  // 자료구조강의라면 이것을 사용하겠지만,
    std::vector<GeometricObject*> object_list;

    object_list.push_back(new Box);
    object_list.push_back(new Circle);

    //GeometricObject* my_box = new Box;
    //GeometricObject* my_circle = new Circle;

    my_box->draw();
    my_circle->draw();
    
    return 0;
}