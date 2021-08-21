#include "iostream"
using namespace std;

class Overload{
   int x;
   public: Overload(int a=0):x(a){
      cout<<"This is overloaded class"<<endl;
   };
   int getX(int a=0) const  //Since this is const, it can't change then values of any member variables
   {
     //x-=a;
     return x-a;
   }
};

class Base{
  protected: int val,res;
  public:
  Base(int x=0,int y=0):val(x),res(y){ cout<<"Hello from Base "<<res<<"  "<<val<<endl; };
  virtual //Late Binding, function mapped at runtime
  void Disp(){
    cout<<"Disp of Base Class"<<endl;
  };
  operator Overload(){
     cout<<"Base is being typecasted into Overloaded"<<endl;
     return Overload(23);
  }
};
class Derived: public Base{
  public: //Derived(){ cout<<"Hello from Derived"<<endl; };  Ambiguity will occur when calling the constructor
  Derived(int x=0,int y=0):Base(x,y){ cout<<"Hello from Derived"<<endl; }
  void Disp(){
    cout<<"Disp of Derived Class"<<endl;
  };

  Derived(Derived &x){                            //A copy constructor always class an object of same type by reference
     cout<<"\nCopy Constructor is Called"<<endl;
     this->res=x.res+3;
     this->val=x.val-2;
  }
  Derived operator=(Derived x){
     cout<<"\nAssignment operator is Called"<<endl;
     Derived b;
     b.res=x.res;
     b.val=x.val;
     return b;
  }
  friend int Result(Derived,int (*fptr)(int));  //Derived class is like Pakistan in this case. If you want to access those data members, you have to do it through Derived
};

int Result(Derived x,int (*fptr)(int)){   //Since we're calling the Derived variable by value, the value of actual parameter is copied into the formal parameter.
    //That's why the copy constructor is called
    cout<<x.res<<"  "<<x.val<<endl;
    return fptr(x.val)-2*x.res+3;
}

int main(){
    Base* const x=new Derived;  //the value of the pointer x can't be changed
    x->Disp();
    auto NiceHash=[](int t)->int{
        if(t==0) cout<<"T = 0"<<endl;
        return 4*t-3;
    };
    Overload p=Base();
    int z=10,y=6;
    const int* a=&z;  //*a=8 is wrong
    int* const b=&z;  //b=&y is wrong
    a=&y; *b-=3;
    cout<<*a<<"  "<<z<<endl;
    cout<<(z-*a)<<"  "<<p.getX(11)<<endl;
    Derived d(5,7);
    cout<<Result(d,NiceHash)<<endl;
    return 0;
}
