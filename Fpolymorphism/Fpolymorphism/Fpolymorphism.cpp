#include <iostream>
#include <string>
#include "Box.h"
#include "Circle.h"
#include "GeometricObject.h"
#include <vector> // array�� ���� ����� ����



int main()
{
    std::cout << "Hello World!\n";

    //GeometricObject** object_list = new GeometricObject * [10];  // �ڷᱸ�����Ƕ�� �̰��� ����ϰ�����,
    std::vector<GeometricObject*> object_list;
    //GeometricObject go;

    object_list.push_back(GeometricObject::getGeometricObject("Box"));
    object_list.push_back(GeometricObject::getGeometricObject("Circle"));
    object_list.push_back(GeometricObject::getGeometricObject("Box"));

    for (auto itr : object_list)
    {
        (itr)->draw();
    }
    return 0;
}