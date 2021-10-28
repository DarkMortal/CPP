#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   vector<int> arr={1,2,3,4,5,6,7,8,9,10};
   stable_sort(arr.begin(),arr.end());
   reverse(arr.begin(),arr.end());
   for(int i:arr) cout<<(i*i+2*i+1)<<" "; cout<<endl<<endl;
   vector<string> Names={"Saptarshi Dey","Dipanjan Biswas","Swagatam Burai","Rishav Gupta"};
   stable_sort(Names.begin(),Names.end());
   for(string name: Names) cout<<name<<endl;
   return 0;
}

/*Output
121 100 81 64 49 36 25 16 9 4

Dipanjan Biswas
Rishav Gupta
Saptarshi Dey
Swagatam Burai
*/
