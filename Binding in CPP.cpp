//Early vs Compiletime Binding
#include <iostream>
#include <tuple>
using namespace std;

typedef tuple<string,uint16_t,string> extendedBase;

class Base{
    protected: string name; uint16_t value;
    public: Base(uint16_t x=0,string str="") noexcept : value(x), name(str){ 
        cout<<"Base class constructor called"<<endl;
    } Base(){ throw string("No empty String Literals allowed"); }
    virtual void Disp() const {
        cout<<"Name : "<<name<<endl;  
        cout<<"Value : "<<value<<endl; 
    } 
};

class Child: public Base{
    string id;
    public: Child(extendedBase b) noexcept : Base(get<1>(b),get<0>(b)), id(get<2>(b)){ 
        cout<<"Child class constructor called"<<endl;
    } Child() = default;
    void Disp() const {
        cout<<"ID : "<<id<<endl;
        cout<<"Name : "<<name<<endl;  
        cout<<"Value : "<<value<<endl; 
    }
};

int main(){
    extendedBase data = make_tuple("Gogeta",9001,"FUSION");
    Base* x = new Child(data);
    cout<<sizeof(Base)<<" "<<sizeof(Child)<<" "<<sizeof(string)<<" "<<sizeof(uint16_t)<<endl;
    x->Disp();
    delete x; return 0;
}

/*Summary : If the compiler knows at the compile-time which function is called, it is called early binding. 
If a compiler does not know at compile-time which functions to call up until the run-time, it is called late binding.

Early Binding
This is compile time polymorphism.
Here it directly associates an address to the function call. 
For function overloading it is an example of early binding.

Late Binding
This is run time polymorphism. 
In this type of binding the compiler adds code that identifies the object type at runtime then matches the call with the right function definition.
This is achieved by using virtual function.
*/

/*Output
Base class constructor called
Child class constructor called
ID : FUSION
Name : Gogeta
Value : 9001
*/