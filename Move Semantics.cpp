#include <iostream>
using namespace std;

// Let's create a Point class which is used by the Line class

class Point{
    uint16_t x,y;
    public: Point(uint16_t a=0,uint16_t b=0) noexcept :x(a),y(b){
        cout<<"\nPoint constructor called";
    }
    // Copy Constructor
    Point(const Point& p) noexcept {
        cout<<"\nCopy constructor of Point is called";
        this->x = p.x;
        this->y = p.y;
    }
    void Disp() const {
        cout<<"\nX : "<<this->x<<endl;
        cout<<"Y : "<<this->y<<endl;
    }
    // Move Constructor
    Point(Point&& p) noexcept {
        cout<<"\nMove constructor of Point is called";
        this->x = p.x;
        this->y = p.y;
    }
};

class Line{
    Point A,B;
    public: Line(Point x,Point y) noexcept : A(x), B(y){
        cout<<"\nLine constructor called";
    }
    Line() = default;
    void Show() const {
        cout<<"\nPoint A :"; A.Disp();
        cout<<"\nPoint B :"; B.Disp();
    }
    // Move Constructor
    Line(Point&& x,Point&& y) noexcept : A(x), B(y){
        cout<<"\nMove constructor of Line called";
    }
};

int main(){
    Line x,y({2,3},{3,4});
    x.Show(); 
    y.Show();
    return 0;
}