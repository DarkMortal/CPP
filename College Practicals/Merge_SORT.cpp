#include <iostream>
using namespace std;

void MERGE(int* a,int mid,int low,int high){
    int i=low,j=mid+1,k=low;
    int c[100];
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            c[k]=a[i];
            k++; i++;
        }
        else{
            c[k]=a[j];
            k++; j++;
        }
    }
    while(i<=mid){
        c[k]=a[i];
        k++; i++;
    }
    while(j<=high){
        c[k]=a[j];
        k++; j++;
    }
    for(i=low;i<=high;i++) a[i]=c[i];
}

void SORT(int* A,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        SORT(A,low,mid);
        SORT(A,mid+1,high);
        MERGE(A,mid,low,high);
    }
}

int main(){
    int a,n; 
    cout<<"Enter no. of integers: "; cin>>n;
    cout<<"Enter the integers"<<endl;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    SORT(arr,0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl; return 0;
}
