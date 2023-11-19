#include <iostream>
#include <map>
using namespace std;

typedef map<int,int> value_store;
value_store memo;

int Fibonacci(int n){
    if(n<=2) return 1;
    if(memo.find(n)!=memo.end()) return memo[n];
    memo[n] = Fibonacci(n-1)+Fibonacci(n-2);
    return memo[n];
}

int main(){
    int x = 0; cin>>x;
    cout<<Fibonacci(x)<<endl;
    return 0; 
}