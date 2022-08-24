#include <iostream>
using namespace std;

class Test{
    uint16_t value;
    public: Test() = default;
    Test(int& x) noexcept : value(x){
        cout<<"L value constructor is called with value = "<<x<<endl;
    }
    Test(int&& x) noexcept : value(x){
        cout<<"R value constructor is called with value = "<<x<<endl;
    }
    Test(const Test& t) noexcept : value(t.value) {
        cout<<"L value copy constructor is called with value = "<<t.value<<endl;
    }
    Test(const Test&& t) noexcept : value(t.value){
        cout<<"R value copy constructor is called with value = "<<t.value<<endl;
    }
    friend uint16_t getValue(Test&);
    friend uint16_t getValue(Test&&);
    void operator = (const Test& t) noexcept {
        this->value = t.value;
        cout<<"Assignment operator called"<<endl;
    }
};

uint16_t getValue(Test& x){
    cout<<"L value Test object with value = "<<x.value<<endl;
    return x.value;
}

uint16_t getValue(Test&& x){
    cout<<"R value Test object with value = "<<x.value<<endl;
    return x.value;
}

int main(){
    int a=2;
    Test p(a),t(3);
    Test x = t, y = Test(4); // Copy constructors called since Variables not initialised yet
    cout<<getValue(y)<<endl; // L-value Test Object
    cout<<getValue(Test(5))<<endl; // R-value Test Object
    cout<<getValue(x)<<endl;
    y = x; // Assignment operator called
    cout<<getValue(y)<<endl; // L-value Test Object
    return 0;
}

/*
int& = lvalue reference
int&& = rvalue reference
Put simply, an lvalue is an object reference and an rvalue is a value
*/

/*Output
L value constructor is called with value = 2
R value constructor is called with value = 3
L value copy constructor is called with value = 3
R value constructor is called with value = 4
L value Test object with value = 4
4
R value constructor is called with value = 5
R value Test object with value = 5
5
L value Test object with value = 3
3
Assignment operator called
L value Test object with value = 3
3
*/