#ifndef COMPLEX_GUARD
#define COMPLEX_GUARD
#include "math.h"
#define DEGREE_TO_RADIAN(x) (x * M_PI) / 180
#define RADIAN_TO_DEGREE(x) (x * 180) / M_PI

namespace Polar_NonPolar
{
    class Cartesian;
    class Polar
    {
        double dist, angle;

    public:
        Polar(double a, double b) : dist(a), angle(b) {}
        Polar()
        {
            dist = 0;
            angle = 0;
        } // In case no parameters provided, this default constructor will be called
        operator Cartesian();
        /*
        We can't define it here since the Cartesian class still isn't defined
        */
        double getRadius() const { return dist; }
        double getAngle() const { return angle; }
    };

    class Cartesian
    {
        double x, y;

    public:
        Cartesian()
        {
            x = 0;
            y = 0;
        }
        Cartesian(double a, double b) : x(a), y(b) {}
        operator Polar()
        { // NOTICE:- No return type is mentioned
            double distance = sqrt(x * x + y * y);
            double angle = atan(y / x);
            angle = RADIAN_TO_DEGREE(angle);
            return Polar(distance, angle); // Note that new keyword is used to return pointers (allocate memory in the heap), don't use it here
        }
        double getX() const { return x; }
        double getY() const { return y; }
    };
    // We can define that operator after we have defined the Class
    Polar::operator Cartesian()
    {
        double x = dist * cos(DEGREE_TO_RADIAN(angle));
        double y = dist * sin(DEGREE_TO_RADIAN(angle));
        return Cartesian(x, y);
    }
}

namespace COMPLEX
{
    class Complex
    {
        double real, img;

    public:
        Complex(double a = 0, double b = 0) : real(a), img(b) {}
        double getReal() const { return real; }
        double getImg() const { return img; }
        double getMOD() const { return sqrt(real * real + img * img); }
        double getARG() const { return atan(img / real); } // Returns the angle in radians
        /*
            Whenever we are overloading an operator, we MUST pass the argument by reference
        */
        Complex operator+(const Complex &x) { return Complex(x.real + this->real, x.img + this->img); }
        Complex operator-(const Complex &x) { return Complex(this->real - x.real, this->img - x.img); }
        Complex operator^(double a)
        { // Power operator
            double mod = pow(getMOD(), a);
            double arg = getARG();
            return Complex(mod * cos(arg * a), mod * sin(arg * a));
        }
        Complex operator*(const Complex &x) { return Complex((this->real * x.real) - (this->img * x.img), (this->real * x.img) + (this->img * x.real)); }

        // Rotating a complex number
        Complex RotateComplex(float DEGREE_IN_RADIANS)
        {
            double rad = getMOD();
            double arg = getARG();
            return Complex(rad * cos(arg + DEGREE_IN_RADIANS), rad * sin(arg + DEGREE_IN_RADIANS));
        }

        static Complex Logarithm(Complex a) { return Complex(log(a.getMOD()), a.getARG()); }
    };
}

#endif // Complex_GUARD
