#include <iostream>
#include <cmath>
#include "point2D.h"

Point2D::Point2D(double x, double y) : m_x{ x }, m_y{ y } {}

void Point2D::print() const
{
	std::cout << "Point2D(" << m_x << ", " << m_y << ")\n";
}

double Point2D::distanceTo(const Point2D& p) const
{
	return std::sqrt((m_x - p.m_x) * (m_x - p.m_x) + (m_y - p.m_y) * (m_y - p.m_y));
}