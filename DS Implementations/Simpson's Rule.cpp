#include<iostream>
#include<math.h>
#define intervals 100
using namespace std;

float Integrate(float lower_limit,float upper_limit,float (*func)(float x)){
    float dx=(upper_limit-lower_limit)/intervals,
        area=func(lower_limit)+func(upper_limit),
        t0=0,t1=0,t2=lower_limit+dx;
    for(int i=1;i<intervals;i++,t2+=dx){
        t1=func(t2);
        t0+=t1;
        if(i%2!=0) t0+=t1;
    }
    area+=(2*t0);
    return (area*dx)/3;
}

int main(){
    auto f=[](float x)->float{ return sqrt(3*x*x+5*x+1.02); };
    float a,b; 
    cout<<"Enter the Intervals = "; cin>>a>>b;
    cout<<"\nThe Integral = "<<Integrate(1,2,f)<<endl;
    return 0;
}