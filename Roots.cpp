#include<bits/stdc++.h>
#define MOD(a) (a<0)?(a*(-1)):(a)
using namespace std;

//Only works in Linux
static char *super[] = {"\xe2\x81\xb0", "\xc2\xb9", "\xc2\xb2", "\xc2\xb3", "\xe2\x81\xb4", "\xe2\x81\xb5", "\xe2\x81\xb6","\xe2\x81\xb7", "\xe2\x81\xb8", "\xe2\x81\xb9"};

void Disp(int n){
    int a=n;
    string x="";
    while(a){
        x+=char(a%10+48);
        a/=10;
    }
    reverse(x.begin(),x.end());
    for(int i=0;i<x.length();i++) cout<<super[x.at(i)-48];
}

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

vector<int> Factorizer(int n){
    vector<int> arr;
    for(int i=1;i<=n/2;i++) if(n%i==0) arr.push_back(i); arr.push_back(n);
    return arr;
}

float polyval(vector<int> a,float x){
    float sum=0.0;
    for(int i=0;i<a.size();i++) sum+=(float(a[i])*pow(x,a.size()-i));
    return sum;
}

int main()
{
    cout<<"1. Roots from equation"<<endl<<"2. Equation from roots"<<endl;
    char ch=getchar(); int n=0;
	if(ch=='1'){
        int a=0;
        vector<int> arr;
        cout<<"Enter degree of polynomial : "; cin>>n;
        if(n>1){
        cout<<"Enter the coefficients of the polynomial in decreasing sequence of their exponents :"<<endl;
        for(int i=0;i<n+1;i++){ cin>>a; arr.push_back(a); }
        if(n==2){
            float d=arr[1]*arr[1]-4*arr[0]*arr[2];
            if(d==0) cout<<"The root is = "<<float(arr[1]*(-1))/float(2*arr[0])<<endl;
            else if(d<0){
                float real=float(arr[1]*(-1))/float(2*arr[0]);
                float img=sqrt(d*(-1))/float(2*arr[0]);
                cout<<"The roots are "<<real<<"+"<<img<<"i and "<<real<<"-"<<img<<"i"<<endl;
            }
            else if(d>0){
                float r1=float(arr[1]*(-1))/float(2*arr[0])-sqrt(d)/float(2*arr[0]);
                float r2=float(arr[1]*(-1))/float(2*arr[0])+sqrt(d)/float(2*arr[0]);
                cout<<"The roots are "<<r1<<" and "<<r2<<endl;
            }
        }
        else if(n>2){
            if(arr[arr.size()-1]%arr[0]==0){
            a=arr[arr.size()-1]/arr[0];
            vector<float> factors;
            if(a==0){
                factors.push_back(0);
                auto index=arr.size();
                while (!arr[index]) index--; index++;
                vector<int> arr2(index);
                copy(arr.begin(),arr.begin()+index,arr2.begin());
                a=arr2[arr2.size()-1]/arr2[0];
                vector<int> factor1=Factorizer(MOD(a));
                for(int i:factor1){
                    if(factors.size()==arr.size()-1) break;
                    else{
                        if(!polyval(arr2,i)) factors.push_back(i);
                        if(!polyval(arr2,i*(-1.0))) factors.push_back(i*(-1));
                    }
                }
            }
            else{
                vector<int> factor1=Factorizer(MOD(a));
                for(int i:factor1){
                    if(factors.size()==arr.size()-1) break;
                    else{
                        if(!polyval(arr,i)) factors.push_back(i);
                        if(!polyval(arr,i*(-1.0))) factors.push_back(i*(-1));
                    }
                }
            }
            if(factors.size()==0) cout<<"No roots found"<<endl;
            else { cout<<"The roots are : "; for(float e:factors) cout<<e<<" "; cout<<endl; }
            } else cout<<"Couldn't determine roots :("<<endl;
        }}else cout<<"Degree must be more than 1"<<endl;
	}
	else if(ch=='2'){
        cout<<"Enter number of Roots = "; cin>>n;
        float arr[n]={0};
        cout<<"Enter the Roots : ";
        for(int j=0;j<n;j++) cin>>arr[j];
        cout<<"Enter variable : "; getchar(); cin>>ch; cout<<ch; Disp(n);
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
                    else{ cout<<ch; Disp(n-i); }
                }
            }
        } cout<<endl;
	}else cout<<"Please select a valid option"<<endl;
    return 0;
}
