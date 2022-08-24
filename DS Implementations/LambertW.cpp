#include<iostream>
#include<math.h>
using namespace std;

double LambertW(double x,int iterations=100){
    if(iterations==1) return log(x);
    else return log(x)-log(LambertW(x,iterations-1));
}

int main(){
    double a; cin>>a;
    a=LambertW(a);
    cout<<a<<endl;
}
