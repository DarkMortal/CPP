#include<iostream>
using namespace std;

typedef float(*Func)(float,float); //These are called function pointers 
using Func2=int(*)(int,int(*)(int)); //This is another way to typedef function pointers
/*
There are 2 ways to typedef in c++
1. typedef datatype typename;
2. using typename= datatype;
*/
struct PrintNum {
   void operator()(float i){    // Using structure as functions void operator()(arguments){ function body;}
      cout << endl<<i<<endl;
   }
   void operator()(){        // Using structure as functions void operator()(arguments){ function body;}
      cout <<"\nTEHEEE";
   }
};


int main(){
	int a=5;
	Func fun1=[](float a,float b){
		cout<<"Product="<<a*b;
		return (a*b);
	};
	
	auto func2=[&a](int x){a+=x;}; 
	//A lambda function can only be initialised as function pointer if and only if there aren't any capture list
	
	Func2 autoFunc=[](int x,int(*newFunc)(int))->int{return newFunc(x)-2;};
	//Edit:- lambda functions can also conatain other lambda functions as a parameters
	
	func2(7); //Incrementing the value of a by 7 i.e a=12
	
	int res2= autoFunc(a,[](int arg){ //You can additionally specify the return type by ->int after the arguments i.e (int arg)->int but that's optional
		return arg*arg;
	});
	
	float res=fun1(12.3,7.1);
	PrintNum obj; obj(res-1); obj(res2); obj();
	return 0;
}

/* Output:-
Product=87.33
86.33

142

TEHEEE
*/
