#include <iostream>
using namespace std;

// RVO stands for Return Value Optimization
// NRVO stands for Named Return Value Optimization

// This feature of the g++ compiler can be disabled using the flag : -fno-elide-constructors

class Base{
    int value;
    public: Base(int x): value(x) { cout<<"Base class initialised with value = "<<x<<endl; }
    Base() = default; // Compiler generates a default constructor in case no parameter is specified
    Base(const Base& b) noexcept {
        cout<<"Copy constructor of base class is called with value = "<<b.value<<endl;
        value = 2*b.value+1;
    }
    int getValue() const { return value; }
    ~Base(){ cout<<"\nDestructor is called"<<endl; }
};

/*  In case of disabled RVO and NRVO, the object returned is first copied to a 
    temoprary object and the value of that object is copied to the memory address of Base b.

    In case of enabled RVO and NRVO, the object is created directly on the memory address of Base b.

    NRVO is when we create an object of Base class and first assign it to a variable and then return that variable.
*/ 

Base getBase(int x){
    return Base(x);
}

int main(){
    Base b = getBase(3);
    Base a = b;
    cout<<endl<<b.getValue()<<" "<<a.getValue()<<endl;
}

/* Output
-----------------------------------------------
Without disabling RVO and NRVO
-----------------------------------------------
Base class initialised with value = 3
Copy constructor of base class is called with value = 3

3 7

Destructor is called

Destructor is called
-----------------------------------------------
With disabling RVO and NRVO
-----------------------------------------------
Base class initialised with value = 3
Copy constructor of base class is called with value = 3

Destructor is called
Copy constructor of base class is called with value = 7

Destructor is called
Copy constructor of base class is called with value = 15

15 31

Destructor is called

Destructor is called
*/