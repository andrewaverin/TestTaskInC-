#include "Figure.h"

Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

const float Vector3D::GetX()
{
	return this->x;
}

const float Vector3D::GetY()
{
	return this->y;
}

const float Vector3D::GetZ()
{
	return this->z;
}

void Vector3D::SetX(double x)
{
	this->x = x;
}

void Vector3D::SetY(double y)
{
	this->y = y;
}

void Vector3D::SetZ(double z)
{
	this->z = z;
}




Ellipse::Ellipse()
{
	this->r1 = 1.0;
	this->r2 = 2.0;
}

Ellipse::Ellipse(double a, double b)
{
	this->r1 = a;
	this->r2 = b;
}

Vector3D Ellipse::GetVector(double t)
{
	return Vector3D(r1 * cos(t), r2 * sin(t), 0.0f);
}

Vector3D Ellipse::GetFirstDerivative(double t)
{
	return Vector3D(-r1 * sin(t), r2 * cos(t), 0.0f);
}

int Ellipse::WhoAmI()
{
	return ELLIPSE_ID;
}


Circle::Circle()
{
	this->r1 = this->r2 = 1.0;
}

Circle::Circle(double r)
{
	this->r1 = this->r2 = r;
}

Vector3D Circle::GetVector(double t)
{
	return Vector3D(r1 * cos(t), r1 * sin(t), 0.0f);
}

Vector3D Circle::GetFirstDerivative(double t)
{
	return Vector3D(-r1 * sin(t), r1 * cos(t), 0.0f);
}

const double Circle::GetRadius()
{
	return this->r1;
}

int Circle::WhoAmI()
{
	return CIRCLE_ID;
}


Helix::Helix()
{
	this->r = 1.0;
	this->step = 2*M_PI;
}

Helix::Helix(double r, unsigned int step)
{
	this->r = r;
	this->step = step;
}

Vector3D Helix::GetVector(double t)
{
	return Vector3D(r * cos(t), r * sin(t), t * step / 2 * M_PI);
}

Vector3D Helix::GetFirstDerivative(double t)
{
	return Vector3D(-r * sin(t), r * cos(t), step / 2 * M_PI);
}

int Helix::WhoAmI()
{
	return HELIX_ID;
}
