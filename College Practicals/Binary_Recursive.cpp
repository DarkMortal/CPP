#include <iostream>
using namespace std;

int Binary(int*,int,int,int);

int main(){
    int a,n; 
    cout<<"Enter no. of integers: "; cin>>n;
    cout<<"Enter the integers in ascending order"<<endl;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<"Enter value to be searched : "; cin>>a;
    int index = Binary(arr,0,n-1,a);
    if(index+1) cout<<"\n"<<a<<" found at "<<index<<" index"<<endl;
    else cout<<"\nValue not Found"<<endl;
    return 0;
}

int Binary(int* arr,int beg,int end,int val){
    if(beg<=end){
        int mid = (beg+end)>>1;
        if(val == arr[mid]) return mid;
        else if(arr[mid]>val) return Binary(arr,beg,mid-1,val);
        else return Binary(arr,mid+1,end,val);
    } else return -1;
}