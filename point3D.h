#pragma once

class Vector3D; // forward declaration for moveByVector function

class Point3D
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;

	void moveByVector(const Vector3D& v);
};
