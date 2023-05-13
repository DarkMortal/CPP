#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
	double real, img;

public:
	Complex(double a, double b)
	{
		real = a;
		img = b;
	}
	Complex operator+(Complex c2)
	{
		Complex temp(0, 0);
		temp.real = real + c2.real;
		temp.img = img + c2.img;
		return temp;
	}
	Complex operator-(Complex c2)
	{
		Complex temp(0, 0);
		temp.real = real - c2.real;
		temp.img = img - c2.img;
		return temp;
	}
	void operator-()
	{
		real = real * (-1);
		img = img * (-1);
	}
	bool operator==(Complex &C)
	{
		if (C.real == real && C.img == img)
			return true;
		else
			return false;
	}
	void disp() { cout << "(" << real << ")"
					   << "+i"
					   << "(" << img << ")"; }
};
class Vector
{
	double x, y, z;

public:
	Vector(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
	}
	Vector operator+(Vector V)
	{
		Vector temp(0, 0, 0);
		temp.x = x + V.x;
		temp.y = y + V.y;
		temp.z = z + V.z;
		return temp;
	}
	Vector operator-(Vector V)
	{
		Vector temp(0, 0, 0);
		temp.x = x - V.x;
		temp.y = y - V.y;
		temp.z = z - V.z;
		return temp;
	}
	bool operator==(Vector &V)
	{
		if (V.x == x && V.y == y && V.z == z)
			return true;
		else
			return false;
	}
	double mod()
	{
		double temp;
		temp = sqrt(x * x + y * y + z * z);
		return temp;
	}
	void disp()
	{
		cout << "(" << x << ")"
			 << "i"
			 << "+(" << y << ")"
			 << "j"
			 << "+(" << z << ")"
			 << "k";
	}
};
