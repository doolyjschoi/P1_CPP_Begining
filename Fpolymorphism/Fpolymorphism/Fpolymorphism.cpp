#include <iostream>
#include "Box.h"
#include "Circle.h"
//#include "GeometricObject.h"
#include <vector> // array�� ���� ����� ����
int main()
{
    std::cout << "Hello World!\n";

    //GeometricObject** object_list = new GeometricObject * [10];  // �ڷᱸ�����Ƕ�� �̰��� ����ϰ�����,
    std::vector<GeometricObject*> object_list;

    object_list.push_back(new Box);
    object_list.push_back(new Circle);

    //GeometricObject* my_box = new Box;
    //GeometricObject* my_circle = new Circle;

    my_box->draw();
    my_circle->draw();
    
    return 0;
}