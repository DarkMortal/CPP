#include<bits/stdc++.h>
using namespace std;

//Only works in Linux
static char *super[] = {"\xe2\x81\xb0", "\xc2\xb9", "\xc2\xb2", "\xc2\xb3", "\xe2\x81\xb4", "\xe2\x81\xb5", "\xe2\x81\xb6","\xe2\x81\xb7", "\xe2\x81\xb8", "\xe2\x81\xb9"};

void combinationUtil(float arr[], float data[],int start, int end,int index, int r,float &elm){
	if (index == r){
        float x=1.0;
		for (int j = 0; j < r; j++) x*=data[j];
        elm+=x; return;
	}

	for (int i = start; i <= end && end - i + 1 >= r - index; i++){
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,end, index+1, r,elm);
	}
}

void sumCombination(float arr[], int n, int r,float &x){
	float data[r]={0};
	combinationUtil(arr, data, 0, n-1, 0, r,x);
}

int main()
{
	int n; char ch;
	cout<<"Enter number of Roots = "; cin>>n;
	if(n>=10) cout<<"Equations of degree more than 9 are not supported"<<endl;
	else{
        float arr[n]={0};
        cout<<"Enter the Roots : ";
        for(int j=0;j<n;j++) cin>>arr[j];
        cout<<"Enter variable : "; getchar(); cin>>ch; cout<<ch<<super[n];
        for(int i=1;i<=n;i++){
            float sum=0.0;
            sumCombination(arr, n, i,sum);
            if(sum){
                sum=(i%2==0)?(sum):(sum*(-1));
                if(sum>0 && sum!=1) cout<<"+"<<sum;
                else if(sum==-1) cout<<"-";
                else if(sum==1) cout<<"+";
                else cout<<sum;
                if(n!=i){
                    if((n-i)==1) cout<<ch;
                    else cout<<ch<<super[n-i];
                }
            }
    }}
	cout<<endl; return 0;
}
