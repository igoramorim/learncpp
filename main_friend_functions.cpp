#include <iostream>
#include "point3D.h"
#include "vector3D.h"

int main()
{
	Point3D p{ 1.0, 2.0, 3.0 };
	Vector3D v{ 2.0, 2.0, -3.0 };

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}