/*PS: 
    given an array where each integer appears twice except for one particular integer 
    find that integer
*/
#include <bits/stdc++.h>

int uniqueIndex(int*, uint16_t); 

int main(){
    int arr[7] = { 1, 2, 3, 5, 1, 2, 3};
    int u = uniqueIndex(arr, sizeof(arr)/sizeof(int));
    std::cout << u << std::endl;
    return 0;
}

int uniqueIndex(int arr[], uint16_t n){
    int u = 0;
    for(uint16_t i = 0; i < n; i++){
        u = u ^ arr[i];
    } return u;
}

/* Output: 5 */