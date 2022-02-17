#include <iostream>
#include "point2D.h"

int main()
{
    Point2D first{};
    Point2D second{ 3.0, 4.0 };
    first.print();
    second.print();
    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	return 0;
}
