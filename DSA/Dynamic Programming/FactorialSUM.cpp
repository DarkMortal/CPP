#include <iostream>
#include <map>
#include "../Sorting/Sorting.hpp"
using namespace std;

map<uint16_t,uint16_t> factors;

int factorial(uint16_t n){
	if(n <= 1) return 1;
	if(factors[n]) return factors[n];
	uint16_t a=n;
	for(uint16_t i=n-1;i>0;i--){
		if(factors[i]) return a*factors[i];
		else a *= i;
	}
	factors[n] = a;
	return a;
}

int main() {
	int n = 0;
	uint16_t sum = 0, e = 0;
	cout<<"Enter the size of array : ";
	cin>>n;
    int arr[n];
	cout<<"Enter the array :\n";
	for(int i=0;i<n;i++) cin>>arr[i];
    Quick_SORT::ASCENDING::SORT(arr,0,n-1);
    for(int i=0;i<n;i++) sum += factorial(arr[i]);
	cout<<"\nThe sum of their factorials is = "<<sum<<endl;
	return 0;
}