#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Disp(vector<int> x,int a){
    cout<<endl;
    cout<<"STEP-"<<a<<": ";
    for(int i=x.size();i>0;i--) cout<<x[i-1]<<" ";
    cout<<endl;
}

bool Havel_Hakimi(vector<int> A,bool z){
    int x=0,n=A.size();
    bool allZero=false;
    std::sort(A.begin(),A.end());
    for(int i=1;i<=n;i++){
        x=A[n-i]; A.pop_back();
        if(x>(n-i)) return false;
        for(int j=i+1;j<=x+i;j++){
            A[n-j]--;
            if(A[n-j]<0) return false;
        }
        allZero=std::all_of(A.begin(),A.end(),[](int i) { return i==0; });
        if(allZero) return true;
        std::sort(A.begin(),A.end());
        if(z) Disp(A,i+1);
    } return true;
}
int main(){
    int n=0,x=0; char ch;
    vector<int> arr;
    cout<<"Enter the Number of vertices = "; cin>>n;
    cout<<"Enter the Degree Sequence :"<<endl;
    for(int i=0;i<n;i++){
        cin>>x; arr.push_back(x);
    }
    cout<<"Do you want to see the Steps? (Y/N)"; getchar(); cin>>ch;
    cout<<((Havel_Hakimi(arr,(ch=='y' || ch=='Y')))?("\nThe Graph is possible"):("\nThe Graph is not possible"))<<endl;
    return 0;
}
