#include<iostream>
#include<math.h>

float Heron(float a,float b,float c){
    float s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

class Point{
    float x,y;
    public: Point(float a=0,float b=0,float c=0):x(a),y(b){}
    //Point():x(0),y(0),z(0){}
    friend float Distance(Point,Point);
};

float Distance(Point a,Point b){
    float p=pow(b.x-a.x,2);
    float q=pow(b.y-a.y,2);
    return sqrt(p+q);
}

int main(){
    Point a(12,5),b(4,15),c(7,18);
    float d1=Distance(a,b);
    float d2=Distance(b,c);
    float d3=Distance(c,a);
    std::cout<<"Area is = "<<Heron(d1,d2,d3)<<" sq. units"<<std::endl;
    return 0;
}
