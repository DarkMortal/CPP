#include<iostream>
using namespace std;

//We ignore the terms that get cancelled and recursively multiply the terms
float Binomial(long n,long i){
    if(i<=0) return 1;
    return float(n)/float(i)*Binomial(n-1,i-1);
}

int main(){
    long x,y,ans;
    cout<<"Enter N and C : ";
    cin>>x>>y;
    if(y>x/2) y=x-y;    //Since nCr = nC(n-r)
    ans=Binomial(x,y);
    cout<<"The Binomail Coefficient is = "<<ans<<endl;
    return 0;    
}