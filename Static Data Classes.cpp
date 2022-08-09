#include<iostream>
#define MACRO(n) 7*n-5
#define MACRO2(n) 4*n-3

using namespace std;

class Base{
    int x,y;
    public: Base(int a,int b):x(MACRO(a)),y(MACRO2(b)){}
    Base():x(0),y(0){cout<<"Constructor of base class is called"<<endl;}
    virtual int Calc() const { return Dragon(); }
    protected: const static int value=15;
    int Dragon() const { return x+y; }

    //Note:- A static data member must be const
    //Note:- const keyword prevents the function from modifying the data members
    //If the virtual keyword was not used for Calc, then early binding or compile-time binding would be performed
    //Virtual keyword is used for Late or run-time binding. Binding refers to the process of converting identifiers to addresses
};

class Derived :public Base{
    protected: int Dragon() const {
        return value;
    };
    static int Vegeta(int a){ return a*(a-1); }

    public: Derived(int p,int q):Base(p,q){};
    Derived(){ cout<<"Constructor of Derived Class is called"<<endl; }
    int Calc() const { return Base::Dragon()+this->Dragon(); }
    friend int Caller(int);

    //Even if we don't specify which Dragon we're using, by default the Dragon defined inside the Derived class will be used
    //Note:- If you're calling a function inside a const function, then the function which is called must also be const
    //Note:- A static member function must not have any qualifiers (like const) but a static data member must be const
    //A friend function is a function that has access to the private as well as protected data members of the class
};

int Caller(int x){ return Derived::Vegeta(x)-Derived::value; }

int main(){
    Derived x(2,3);
    cout<<x.Calc()<<endl;
    Base* a=new Derived;
    cout<<a->Calc()<<" "<<Caller(12)<<endl;
    delete a; return 0;
}

/*Output
33
Constructor of base class is called
Constructor of Derived Class is called
15 117
*/
