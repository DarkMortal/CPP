#include<math.h>

namespace Polar_NonPolar{
    class Cartesian;
    class Polar{
       double dist,angle;
       public:
       Polar(double a,double b): dist(a),angle(b){}
       Polar(){ dist=0; angle=0; }  //In case no parameters provided, this default constructor will be called
       operator Cartesian();
       /*
       We can't define it here since the Cartesian class still isn't defined
       */
       double getRadius() const { return dist; }
       double getAngle() const { return angle; }
    };

    class Cartesian{
       double x,y;
       public: Cartesian(){ x=0; y=0; }
       Cartesian(double a,double b): x(a),y(b){}
       operator Polar(){   //NOTICE:- No return type is mentioned
         double distance= sqrt(x*x+y*y);
         double angle= atan(y/x);
         angle=(angle*180)/M_PI;
         return Polar(distance,angle);  //Note that new keyword is used to return pointers (allocate memory in the heap), don't use it here
       }
       double getX() const { return x; }
       double getY() const { return y; }
    };
    //We can define that operator after we have defined the Class
    Polar::operator Cartesian(){
          double x=dist*cos((angle/180)*M_PI);
          double y=dist*sin((angle/180)*M_PI);
          return Cartesian(x,y);
    }
}

namespace Complex{
    class Complex{
        double real,img;
        public: Complex(double a=0,double b=0):real(a),img(b){}
        double getReal() const { return real; }
        double getImg() const { return img; }
        double getMod() const { return sqrt(real*real+img*img); }
        double getArg() const { return atan(img/real); }
        /*
            Whenever we are overloading an operator, we MUST pass the argument by reference
        */
        Complex operator+(const Complex &x){ return Complex(x.real+this->real,x.img+this->img); }
        Complex operator-(const Complex &x){ return Complex(this->real-x.real,this->img-x.img); }
        Complex operator^(double a){        //Power operator
            double mod=pow(getMod(),a);
            double arg=getArg();
            return Complex(mod*cos(arg*a),mod*sin(arg*a));
        }
        Complex operator*(const Complex &x){ return Complex((this->real * x.real)-(this->img * x.img),(this->real * x.img)+(this->img * x.real)); }
    };
}
