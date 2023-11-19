#include <bits/stdc++.h>
using namespace std;

//Print all possible strings of 0s and 1s whose length is n

void Binary(unsigned int n,char* str=nullptr,int start=0){
    if(start==n-1){
        cout<<str<<endl;
        return;
    }
    else{
        char arr0[n]={0},arr1[n]={0};
        if(str != nullptr){
            strcpy(arr0,str);
            strcpy(arr1,str);
        }
        arr0[start]='0';
        arr1[start]='1';
        Binary(n,arr0,start+1);
        Binary(n,arr1,start+1);
    }
}

int main() {
	unsigned int n = 0;
	cout<<"Enter no. of bits = "; cin>>n;
	cout<<"All possible "<<n<<" bit strings of 0s and 1s :\n";
	Binary(n+1); return 0;
}

//No memory leaks possible. Checked with valgrind
