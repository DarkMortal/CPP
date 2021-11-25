#include<iostream>
#include<Sorting.h>
using namespace std;

template <class X>
void SORT(X* arr,int LENGTH,bool D){
    if(D) Merge_SORT::DESCENDING::SORT(arr,0,LENGTH-1);
    else Quick_SORT::ASCENDING::SORT(arr,0,LENGTH-1);
}
/*
void SORT(X* arr,int LENGTH,bool D){
    if(D) Quick_SORT::DESCENDING::SORT(arr,0,LENGTH-1);
    else Merge_SORT::ASCENDING::SORT(arr,0,LENGTH-1);
}
*/

int main(){
    int SIZE;
    cout<<"Enter size of Array = "; cin>>SIZE;
    float arr[SIZE];
    cout<<"Enter the Array :"<<endl;
    for(int i=0;i<SIZE;i++) cin>>arr[i];
    cout<<"Ascending or Descending (A/D)";
    getchar(); char ch;
    cin>>ch;
    bool x=(ch=='D' || ch=='d')?(true):(false);
    SORT(arr,SIZE,x);
    cout<<"The sorted Array is :"<<endl;
    for(int i=0;i<SIZE;i++) cout<<arr[i]<<" ";
    return 0;
}
