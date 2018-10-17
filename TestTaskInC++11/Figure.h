#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include<iostream>


class Vector3D
{
public:
	Vector3D(double x, double y, double z);
	const float GetX();
	const float GetY();
	const float GetZ();
	void SetX(double x);
	void SetY(double y);
	void SetZ(double z);

private:
	double x, y, z;
};

class Figure
{
public:
	virtual Vector3D GetVector(double t) = 0;
	virtual Vector3D GetFirstDerivative(double t) = 0;
	virtual int WhoAmI() = 0;
};

class Ellipse : public Figure
{
public:
	static const int ELLIPSE_ID = 0;

	Ellipse();
	Ellipse(double a, double b);
	Vector3D GetVector(double t) override;
	Vector3D GetFirstDerivative(double t) override;
	int WhoAmI() override;

protected:
	double r1, r2;
};

class Circle : public Ellipse
{

public:
	static const int CIRCLE_ID = 1;
	Circle();
	Circle(double r);
	Vector3D GetVector(double t) override;
	Vector3D GetFirstDerivative(double t) override;
	const double GetRadius();
	int WhoAmI() override;
};

class Helix : public Figure
{
public:
	static const int HELIX_ID = 2;
	Helix();
	Helix(double r, unsigned int step);
	Vector3D GetVector(double t) override;
	Vector3D GetFirstDerivative(double t) override;
	int WhoAmI() override;

private:
	double r;
	unsigned int step;
};
