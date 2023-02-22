/*PS:
    Count of distinct characters at even  positions for different usernames are as follows :

    abcdef = 3
    pqrs = 2
    xyzuvabb = 4
    aaaaaa = 1
*/

#include <bits/stdc++.h>

uint16_t evenDistinct(char*,int);

int main(){
    uint16_t n, len;
    std::cout << "Enter number of strings : ";
    std::cin >> n;
    std::cout << "Enter max length of strings : ";
    std::cin >> len;
    std::cout << "Enter the strings : " << std::endl;
    char str[len] = {0};        // NOTE: old compilers might give this error that variable array can't be innitialised
    for(uint16_t i = 0; i < n; i++){
        std::cin >> str;
        std::cout << evenDistinct(str, strlen(str)) << std::endl;
    }
    return 0;
}

uint16_t evenDistinct(char* str, int n){
    uint16_t c = 0, check = 0;
    for(uint16_t i = 1; i < n; i += 2){
        uint16_t val = i[str] - 'a';
        c += (check & (1 << val)) == 0;
        check |= (1 << val);
    }
    return c;
}

/* Output:
    Enter number of strings : 4
    Enter max length of strings : 8
    Enter the strings : 
    abcdef
    3
    pqrs
    2
    xyzuvabb
    4
    aaaaaa
    1
*/