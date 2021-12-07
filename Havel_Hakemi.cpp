#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Havel_Hakimi(vector<int> A){
    int x=0,n=A.size();
    std::sort(A.begin(),A.end());
    for(int i=1;i<=n;i++){
        x=A[n-i]; A.pop_back();
        if(x>(n-i)) return false;
        for(int j=i+1;j<=x+i;j++){
            A[n-j]--;
            if(A[n-j]<0) return false;
        }
        std::sort(A.begin(),A.end());
    } return true;
}
int main(){
    int n=0,x=0;
    vector<int> arr;
    cout<<"Enter the Number of vertices = "; cin>>n;
    cout<<"Enter the Degree Sequence :"<<endl;
    for(int i=0;i<n;i++){
        cin>>x; arr.push_back(x);
    }
    cout<<((Havel_Hakimi(arr))?("The Graph is possible"):("The Graph is not possible"))<<endl;
    return 0;
}
