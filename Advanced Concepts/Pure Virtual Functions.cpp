#include<iostream>
using namespace std;

class Base{ //This is an abstract class since it contains a pure virtual function
	public:
	virtual void Disp(){   //This function won't be called if this function is overloaded in the derived class
		cout<<"Base::Disp()"<<endl;
	}
	virtual int Resursive_ADD(int x)=0;  //This is a pure virtual function
	//A class containing atleast one pure virtual function can't instaniated (make an object of)
};
class Derived: public Base{
	public:
	void Disp(){
		cout<<"Derived::Disp()"<<endl;
	}
	virtual int Resursive_ADD(int x){    //Since this method is declared (even if it wasn't virtual), now an object of this class can be made
		if(x==1) return 1;
		else return (x+Resursive_ADD(x-1));
	}
};
int main(){
	Base* x=new Derived;  //A pointer of base class can hold the address of a derived class
	x->Disp(); //Late binding or run-time binding
	/*At compile time, the compiler doesn't consider the adress the pointer is holding since memory isn't allocated
	so it considers the pointer type to call the function. If the virtual keyword wasn't used before the function
	declaration, it would have called the Disp() function of the Base class and that is called Early
	Binding or compiler-time binding*/
	cout<<x->Resursive_ADD(6);
	return 0;
}
/*Output:-
Derived::Disp()
21
*/
