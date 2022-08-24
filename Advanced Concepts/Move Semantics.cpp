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
    public: Line(Point& x,Point& y) noexcept : A(x), B(y){
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
    Point a(1,2),b={2,3};
    // Move constructor will be called for y but not for x
    Line x(a,b),y({2,3},{3,4});
    x.Show(); 
    y.Show();
    // Move constructor will be called for l
    Line l({2,3},{4,5});
    l.Show();
    return 0;
}

/*Output

Point constructor called
Point constructor called
Copy constructor of Point is called
Copy constructor of Point is called
Line constructor called
Point constructor called
Point constructor called
Copy constructor of Point is called
Copy constructor of Point is called
Move constructor of Line called
Point A :
X : 1
Y : 2

Point B :
X : 2
Y : 3

Point A :
X : 2
Y : 3

Point B :
X : 3
Y : 4

Point constructor called
Point constructor called
Copy constructor of Point is called
Copy constructor of Point is called
Move constructor of Line called
Point A :
X : 2
Y : 3

Point B :
X : 4
Y : 5
*/