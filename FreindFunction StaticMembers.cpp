#include <iostream>
using namespace std;

class adder{
  public:
    void add(){ cout <<"This add() function from adder class"; }
    void disp(){ cout<<"\nThis is disp() function";}
};

class int_adder : public adder{
  static const int data=10;  //If we are initialising a static data member, it has to be const. I guess in java we don't have that limitation
  //if we had used using adder::add here, then it would have been private
  public:
     //int_adder(int a): data(a){}
     using adder::add;        //we have to expose the parent class since the signature of the previous function has been overloaded
     int add(int a, int b){
          return (a + b);
     }
     static void Show(int x){
     	cout<<"\nThis is Show() function="<<x<<endl;
	 }
	 friend int update(int x); // Friend functions are functions that has the authority to access the private data members of the class both static and non-static
};

int update(int x){return (int_adder::data+x);}
int main(){
  int_adder ia;
  ia.add(); // optionally, we can also use ia.adder::add() and then we don't need to use adder::add in class declaration
  ia.disp(); // Since this function is not being overloaded, we don't need to use :: operator
  int_adder::Show(update(33)); //Since this function is a static one, we can call it even without using the object of the class
  /*I mean you can call it from the object, but it would just take up more memory
  Also static member functions can only access the static data members of the class*/
  cout<<ia.add(10, 20)<<endl;
  return 0;
}

/* Output:-
This add() function from adder class
This is disp() function
This is Show() function=43
30
*/
