#include<iostream>
#include<vector>
using namespace std;

template<typename X>
void Disp(X a);

int main(){
   try{
     int n,a;
     cout<<"Enter N="; cin>>n;
     cout<<"Enter A="; cin>>a;
     vector<int> arr; arr.resize(n,a); //resizes the vector and intializes each value of vector with 11
     //we can also use arr.resize(n) without any initial value
     if(n==arr.size()) //arr.size() is used to get the size of the vector
        cout<<"Given Byte Size="<<n*sizeof(int);
     for(int i=0;i<n;i++){
        //Disp(12.35); //throws an error of type string
        Disp(static_cast<int>(arr[i]));  //static_cast = normal cast like (int)data;
        cout<<endl<<(arr[i]-arr.back()); //arr.back() used to get last element of the vector
     }
   }catch(string error){
     cout<<endl<<error<<endl;  //That error gets handles here in this catch block
   }catch(...){    //If all the catch block fails to handle the error, it gets handled here
      cout<<"\nGarbar hogaya"<<endl;
   }
   return 0;
}

template<typename X>
void Disp(X a){
   string str="There was an Error";
   if(typeid(int)!=typeid(a)){
      cout<<endl<<typeid(a).name()<<endl;  //Displays the typeid of the datatype
      throw str;
   }
   else cout<<"\nValue="<<a;
}
