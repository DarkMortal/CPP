#include<bits/stdc++.h>

class ValueOutOfBounds : public std::exception {
    private: char* message;
    public: ValueOutOfBounds(char* err):message(err){}
    char* what () { return message; }
};

double LambertW(double x,uint16_t iterations = 100){
    if(x<0) throw ValueOutOfBounds("Value must be greater than or equal to 0");
    if(iterations == 1) return log(x);
    else return log(x)-log(LambertW(x,iterations-1));
}

// Driver Code
int main(){
    try{
        double x,y; 
        std::cout<<"Enter number (greater than equal to 0) : ";
        std::cin>>x; 
        y = LambertW(x);
        std::cout<<"W("<<x<<") = "<<std::setprecision(6)<<y<<std::endl;
        std::cout<<y<<"*exp("<<y<<") = "<<y*exp(y)<<std::endl;
    }catch(ValueOutOfBounds err){
        std::cout<<err.what()<<std::endl;
    }
}
