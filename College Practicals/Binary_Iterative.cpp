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
    int s=beg , e=end, pos=-1;
    while(s<=e){
        int mid = (s+e)>>1;
        if(val == arr[mid]){
            pos = mid;
            break;
        }else if(arr[mid]<val) s=mid+1;
        else e=mid-1;
    } return pos;
}