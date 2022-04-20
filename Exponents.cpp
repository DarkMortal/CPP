#include<iostream>
using namespace std;

double exp(double x){
    double a=x,sum=0;
    const unsigned int n=20;
    for(float i=1.0;i<=n;i+=1.0){
        sum+=a;
        a*=(x/(i+1));
    }
    return sum+1;
}

double LambertW(double x,int iterations=100){
    if(iterations==1) return log(x);
    else return log(x)-log(LambertW(x,iterations-1));
}

int main(){
	double x=LambertW(5);
	cout<<"exp(1) = "<<exp(1.0)<<endl;
	cout<<x<<"*exp("<<x<<") = "<<x*exp(x)<<endl;
}