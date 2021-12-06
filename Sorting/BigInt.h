#include<iostream>
#ifndef BIG_INT
#define BIG_INT
using namespace std;

class BigInt{
    string mag; bool isneg;
    public: BigInt(string str=""){ Set(str); }
    string GetString() const {return (isneg)?("-"+mag):(mag);}

    BigInt operator + (const BigInt&);
    BigInt operator - (const BigInt&);
    bool operator > (const BigInt&);
    bool operator < (const BigInt&);
    bool operator == (const BigInt&);

    protected: void Set(string);
    void reverseStr(string&);
    string ADD(string,string);
    string MINUS(string,string);
};

BigInt BigInt::operator+(const BigInt &a){
    if(isneg==a.isneg) return BigInt((isneg)?("-"+ADD(mag,a.mag)):(ADD(mag,a.mag)));
    else{
        bool neg=false;
        if(mag.length()!=a.mag.length()) neg=(mag.length()>a.mag.length() && isneg);
        else neg=(mag>a.mag && isneg);
        return BigInt((neg)?("-"+MINUS(mag,a.mag)):(MINUS(mag,a.mag)));
    }
}

BigInt BigInt::operator-(const BigInt &a){
    if(isneg==a.isneg){
        bool neg=false;
        if(mag.length()!=a.mag.length()) neg=(mag.length()>a.mag.length() && isneg);
        else neg=(mag>a.mag && isneg);
        return BigInt((neg)?("-"+MINUS(mag,a.mag)):(MINUS(mag,a.mag)));
    }
    else return BigInt((isneg)?("-"+ADD(mag,a.mag)):(ADD(mag,a.mag)));
}

void BigInt::Set(string str){
    if(str[0]=='-'){
        isneg=true;
        if(str[1]=='0'){
        int index=1;
        while(str[index]=='0') index++;
        mag=str.substr(index,str.length());
        } else mag=str.substr(1,str.length());
    }
    else{
        isneg=false;
        if(str[0]=='0'){
        int index=0;
        while(str[index]=='0') index++;
        mag=str.substr(index,str.length());
        } else mag=str;
    }
}

bool BigInt::operator > (const BigInt &a){
    if(a.isneg==isneg){
        if(!isneg){
            if(a.mag.length()==mag.length()) return (mag>a.mag);
            else return (mag.length()>a.mag.length());
        }
        else{
            if(a.mag.length()==mag.length()) return (mag<a.mag);
            else return (mag.length()<a.mag.length());
        }
    }else return !isneg;
}

bool BigInt::operator < (const BigInt &a){
    if(a.isneg==isneg){
        if(!isneg){
            if(a.mag.length()==mag.length()) return (mag<a.mag);
            else return (mag.length()<a.mag.length());
        }
        else{
            if(a.mag.length()==mag.length()) return (mag>a.mag);
            else return (mag.length()>a.mag.length());
        }
    }else return isneg;
}

bool BigInt::operator == (const BigInt &a){ return (mag==a.mag && isneg==a.isneg); }

void BigInt::reverseStr(string& str){
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    swap(str[i], str[n - i - 1]);
}

string BigInt::ADD(string A,string B){
    string str="";
    int sum=0,carry=0;
    string max=(A.length()>B.length())?(A):(B);
    string min=(max==B)?(A):(B);
    int count=max.length()-min.length();
    for(int i=0;i<min.length();i++){
        int x=min.at(min.length()-i-1)-48;
        int y=max.at(max.length()-i-1)-48;
        sum=(x+y+carry)%10;
        carry=(x+y+carry)/10;
        str+=char(sum+48);
    }
    while(carry){
        if(count){
            int z=max.at(count-1)-48;
            sum=(z+carry)%10;
            carry=(z+carry)/10;
            str+=char(sum+48);
            count--;
        }
        else{ str+=char(carry+48); carry=0; }
    }
    for(int i=count;i>0;i--) str+=max.at(i-1);
    reverseStr(str); return str;
}

string BigInt::MINUS(string A,string B){
    string str="";
    int diff=0,carry=0;
    string min="",max="";
    if(A.length()!=B.length()) max=(A.length()>B.length())?(A):(B);
    else max=(A>B)?(A):(B);
    min=(max==B)?(A):(B);
    int count=max.length()-min.length();
    for(int i=0;i<min.length();i++){
        int x=min.at(min.length()-i-1)-48;
        int y=max.at(max.length()-i-1)-48;
        if(y<x) diff=(10+y-x-carry)%10;
        else diff=(y-x-carry)%10;
        carry=(y<x)?(1):(0);
        str+=char(diff+48);
    }
    if(carry){
        int z=max.at(count-1)-1;
        str+=char(z); count--;
    }
    for(int i=count;i>0;i--) str+=max.at(i-1);
    reverseStr(str); return str;
}
#endif // BIG_INT
