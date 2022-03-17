#include<iostream>
#include<math.h>
using namespace std;

struct Point{
    float x,y;
    Point(float a=0,float b=0):x(a),y(b){}
    bool operator == (const Point& B){ return (this->x==B.x && this->y==B.y); }
};

class Line{
    Point start,end;
    float slope,constant;
    public:
    Line(Point A,Point B):start(A),end(B){ 
        if(start==end) throw std::string("Points are the same");
        slope = (A.y-B.y)/(A.x-B.x); 
        constant = slope*(-1)*(start.x)+start.y;
    }
    float Dist() const;
    float operator ()(float x){ return slope*x+constant; }
    bool operator ||(const Line& L){ return (this->slope==L.slope); }   //Checks if the lines are parallel or not
    Point operator |(const Line& L){    //TODO: To find coordinates of intersection of 2 lines
        if(this->slope==L.slope) throw std::string("The Lines are Parallel");
        float x=(L.constant-this->constant)/(this->slope-L.slope),
        y=slope*x+constant;
        return Point(x,y);
    }
};

//NOTE:- Operators don't work with Objects defined with qualifiers (like const)

int main(){
    try{
        Line L1(Point(1,1),Point(2,3));
        float y=L1(3);
        cout<<"Value of L1 at 3 = "<<y<<endl<<"and distance = "<<L1.Dist()<<endl;
        Line L2(Point(1,2),Point(0,0));
        Point p=L1|L2;
        cout<<"The coordinates of Intersection are = "<<p.x<<" "<<p.y<<endl;
    }catch(string err){ cout<<err<<endl; }
    return 0;
}

float Line::Dist() const{ 
    float x=start.x-end.x,
    y=start.y-end.y;
    return sqrt(x*x+y*y); 
}