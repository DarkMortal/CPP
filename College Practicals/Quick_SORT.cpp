#include <iostream>
using namespace std;

int DIVIDE(int* arr,int indeint,int len){
    int LOW=indeint+1;
    int HIGH=len;
    do{
        while(arr[LOW]<arr[indeint] || arr[LOW]==arr[indeint]) LOW++;
        while(arr[HIGH]>arr[indeint]) HIGH--;
        if(LOW<HIGH) swap(arr[LOW],arr[HIGH]);
    }while(LOW<HIGH);
    if(indeint!=HIGH) swap(arr[indeint],arr[HIGH]);
    return HIGH;
}

void SORT(int* arr,int START,int END){
    int p_indeint=0;
    if(START<END){
        p_indeint=DIVIDE(arr,START,END);
        SORT(arr,START,p_indeint-1);
        SORT(arr,p_indeint+1,END);
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