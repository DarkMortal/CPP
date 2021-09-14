#include<iostream>
#include<cstdlib>
using namespace std;

class Stack{
   int top,capacity,*arr;
   public: Stack(int n=0):top(-1),capacity(n){ arr=(int*)calloc(n,sizeof(int)); }
   ~Stack(){ delete arr,this; }
   void Push(int x){
     if(top!=(capacity-1)){
        arr[top+1]=x; top++;
     } else throw string("Stack is Full");
   }
   void Pop(){
     if(top!=-1){
        arr[top+1]=0; top--;
   }}
   bool isEmpty(){
     if(top==-1) return true;
     return false;
   }
   bool isFull(){
     if(top==(capacity-1)) return true;
     return false;
   }
   void Change(int pos,int val){
     if(pos<capacity && pos>=0) arr[pos]=val;
     else throw string("Invalid Position");
   }
   int GetVal(int pos){
     if(pos<capacity && pos>=0) return arr[pos];
     else throw string("Invalid Position");
   }
   int Count(){ return top+1; }
};
int main(){
  try{
      int n=0; //throw 2;
      cout<<"Enter number of Elements = "; cin>>n;
      Stack x(n);
      cout<<"Count = "<<x.Count()<<endl;
      for(int i=0;i<n;i++) x.Push(i*i+2*i+1);
      cout<<"Count = "<<x.Count()<<endl;
      for(int i=0;i<n;i++) cout<<x.GetVal(i)<<" ";
      x.Pop();
      cout<<endl<<x.Count();
      //x.Push(22); x.Push(12);
  }catch(string str){
     cout<<endl<<str<<endl;
  }catch(...){
     cout<<"\nAn unknown error has occurred"<<endl;
  }
  return 0;
}
