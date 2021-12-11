#include<bits/stdc++.h>
using namespace std;

const std::unordered_map<int, std::string> kSuperscripts = {
        { 0, "⁰" },
        { 1, "¹" },
        { 2, "²" },
        { 3, "³" },
        { 4, "⁴" },
        { 5, "⁵" },
        { 6, "⁶" },
        { 7, "⁷" },
        { 8, "⁸" },
        { 9, "⁹" },
};

void combinationUtil(int arr[], int data[],int start, int end,int index, int r,int &elm){
	if (index == r){
        int x=1;
		for (int j = 0; j < r; j++) x*=data[j];
        elm+=x; return;
	}

	for (int i = start; i <= end && end - i + 1 >= r - index; i++){
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,end, index+1, r,elm);
	}
}

void sumCombination(int arr[], int n, int r,int &x){
	int data[r];
	combinationUtil(arr, data, 0, n-1, 0, r,x);
}

int main()
{
	int n; char ch;
	cout<<"Enter number of Roots = "; cin>>n;
	if(n>=10) cout<<"Equations of degree more than 9 are not supported"<<endl;
	else{
        int arr[n];
        cout<<"Enter the Roots : ";
        for(int j=0;j<n;j++) cin>>arr[j];
        cout<<"Enter variable : "; getchar(); cin>>ch; cout<<ch<<kSuperscripts.at(n);
        for(int i=1;i<=n;i++){
            int r=i,sum=0;
            sumCombination(arr, n, r,sum);
            if(sum){
                sum=(i%2==0)?(sum):(sum*(-1));
                if(sum>0 && sum!=1) cout<<"+"<<sum;
                else if(sum==-1) cout<<"-";
                else if(sum==1) cout<<"+";
                else cout<<sum;
                if(n!=i){
                    if((n-i)==1) cout<<ch;
                    else cout<<ch<<kSuperscripts.at(n-i);
                }
            }
    }}
	cout<<endl; return 0;
}
