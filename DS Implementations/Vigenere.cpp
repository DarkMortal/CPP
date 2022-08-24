#include<iostream>
#include<algorithm>
using namespace std;

string encrypt(string text,string key){
    string key2="";
    int rep=text.size()/key.size();
    int rem=text.size()%key.size();
    for(int i=0;i<rep;i++) key2+=key;
    key2+=key.substr(0,rem);
    string encrypted="";
    int temp=0;
    for(int i=0;i<text.size();i++){
        temp=(int(text.at(i))+int(key2.at(i))-129)%26+64;
        if(temp==64) encrypted+="Z";
        else encrypted+=char(temp);
    } return encrypted;
}

string decrypt(string text,string key){
    string key2="";
    int rep=text.size()/key.size();
    int rem=text.size()%key.size();
    for(int i=0;i<rep;i++) key2+=key;
    key2+=key.substr(0,rem);
    string decrypted="";
    int temp=0;
    for(int i=0;i<text.size();i++){
        temp=(int(text.at(i))-int(key2.at(i))+26)%26+65;
        if(temp==64) decrypted+="Z";
        else decrypted+=char(temp);
    } return decrypted;
}

int main(){
    string text="",key="",res="";
    int a;
    cout<<"1. Encrypt a Text"<<endl<<"2. Decrypt a Cipher"<<endl;
    cin>>a;
    switch(a){
        case 1:{
            cout<<"Enter the text : "; cin>>text;
            cout<<"Enter the key : "; cin>>key;
            transform(text.begin(),text.end(),text.begin(),::toupper);
            transform(key.begin(),key.end(),key.begin(),::toupper);
            cout<<"Encrypted cipher : "<<encrypt(text,key)<<endl;
            break;
        }
        case 2:{
            cout<<"Enter the cipher : "; cin>>text;
            cout<<"Enter the key : "; cin>>key;
            transform(text.begin(),text.end(),text.begin(),::toupper);
            transform(key.begin(),key.end(),key.begin(),::toupper);
            cout<<"Decrypted text : "<<decrypt(text,key)<<endl;
            break;
        }
        default: { cout<<"Wrong choice entered!!!"<<endl; }
    }
    return 0;
}
