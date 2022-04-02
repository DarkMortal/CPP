#include<bits/stdc++.h>
using namespace std;

int main(int num_args,char** args){
    cout<<"The program has "<<num_args<<" arguments"<<endl;
    for(int i=0;i<num_args;i++) cout<<i+1<<". "<<args[i]<<endl;
    return 0;
}