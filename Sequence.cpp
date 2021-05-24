/* The aim of this program is to find if a string is a subsequence of another string*/

#include<iostream>
#include<string.h>
using namespace std;

bool isSub(char* str,char* sub){
   int a=strlen(str);
   int b=strlen(sub);
   int findex=0,how=0;
   bool isfound=false;
   if(b>a) return false;
   else{
      for(int i=0;i<b;i++){
        isfound=false;
        for(int j=findex;j<a;j++){
            if(str[j]==sub[i]){
                findex=j+1;
                isfound=true;
                break;
            }
        } if(!isfound) return false;
      }
   } return true;
}

void clean(char* str){
  int n=strlen(str);
  for(int i=0;i<n;i++) str[i]=0;
}

int main(){
    int N=0;
    char base[100],word[100];
    cin>>base>>N;
    for(int i=0;i<N;i++){
       cin>>word;
       if(isSub(base,word)) cout<<"POSITIVE"<<endl;
       else cout<<"NEGATIVE"<<endl;
       clean(word);  //Or we can use memset(word, 0, sizeof word) which is defined in the string.h header file
       //and it resets the memory of the entire block with the given value (0 in this case)
    }
    return 0;
}
