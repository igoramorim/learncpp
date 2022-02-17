#pragma once

class Point2D
{
private:
	double m_x;
	double m_y;

public:
	Point2D(double x = 0.0, double y = 0.0);

	void print() const;

	double distanceTo(const Point2D& p) const;
};
