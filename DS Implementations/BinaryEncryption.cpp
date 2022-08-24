#include<iostream>
#include<math.h>
#include<sstream>
using namespace std;

string Binary(char c){
   int n=c;
   string res="";
   while(n){
     res+=char(48+n%2);
     n/=2;
   }
   int x=res.length();
   for (int i=0;i<x/2;i++)
      swap(res[i],res[x-i-1]);
   return res;
}

string Text_to_Binary(string str){
   string res="";
   int x=str.length();
   for(int i=0;i<x-1;i++) res+=Binary(str.at(i))+" ";
   res+=Binary(str.at(x-1));
   return res;
}
char BinaryChar(string str){
   int x=str.length();
   int res=0;
   for(int i=0;i<x;i++){
     if(str.at(i)=='1')
       res+=pow(2,x-i-1);
   }
   return char(res);
}

string Binary_to_Text(string str){
   stringstream ss(str);
   string bits,res="";
   while(ss>>bits)
     res+=BinaryChar(bits);
   return res;
}

int main(){
   int x=0; string str="";
   cout<<"1. Encrypt Text to Binary"<<endl<<"2. Decrypt Binary to Text"<<endl<<"Enter your choice:- ";
   cin>>x;
   switch(x){
     case 1:{
       cin.ignore(numeric_limits<streamsize>::max(),'\n');  //Discards the input buffer from the previous input
       cout<<"\nEnter the Text:-"<<endl;
       getline(cin,str);
       str=Text_to_Binary(str);
       cout<<endl<<"Encrypted Text:-"<<endl<<str<<endl;
       break;
     }
     case 2:{
       cin.ignore(numeric_limits<streamsize>::max(),'\n');  //Discards the input buffer from the previous input
       cout<<"\nEnter the Encrypted Text:-"<<endl;
       getline(cin,str);
       str=Binary_to_Text(str);
       cout<<endl<<"Decrypted Text:-"<<endl<<str<<endl;
       break;
     }
     default: cout<<"\nPlease select a valid option"<<endl;
   }
   return 0;
}
