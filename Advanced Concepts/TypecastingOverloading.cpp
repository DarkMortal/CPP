#include<iostream>
#include<math.h>
using namespace std;

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
   friend double getDATA(Polar,int);
};

double getDATA(Polar a,int opt=1){
   if(opt==1) return a.dist;
   else return a.angle;
}

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
   void Disp(){
     cout<<"X = "<<x<<endl<<"Y = "<<y<<endl;
   }
};
//We can define that operator after we have defined the Class
Polar::operator Cartesian(){
      double x=dist*cos((angle/180)*M_PI);
      double y=dist*sin((angle/180)*M_PI);
      return Cartesian(x,y);
}

int main(){
  double x,y;
  cout<<"Enter the X and Y coordinates= "; cin>>x>>y;
  Cartesian c(x,y);
  Polar p=c;
  cout<<"Distance= "<<getDATA(p)<<endl;
  cout<<"Gradient= "<<getDATA(p,3)<<endl;
  Cartesian a=p;
  a.Disp();
  return 0;
}
