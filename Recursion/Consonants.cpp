#include<bits/stdc++.h>
using namespace std;

const char* vowels = "aeiouAEIOU";

bool checkVowel(char c){
    for(int i=0;i<10;i++){
        if(c == vowels[i]) return true;
    }
    return false;
}

int Consonants(char* str){
    if(str[0] == 0) return 0;
    int count = (checkVowel(str[0]) || str[0]==' ')?0:1;
    return Consonants(str+1)+count;
}

int main(){
    char str[100];
    cout<<"Enter the String :\n";
    cin.getline(str,100,'\n');
    cout<<"No. of Consonants = "<<Consonants(str)<<endl;
    return 0;
}
