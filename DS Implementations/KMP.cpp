#include <bits/stdc++.h>
using namespace std;

bool isSubString(char* str, char* pattern, uint16_t stringLength, uint16_t patternLength){
    if(patternLength > stringLength) return false;

    uint16_t prefixArray[patternLength] = {0}, i = 0, j = 1;
    while(j<patternLength && i<patternLength){
        if(pattern[i] == pattern[j]){
            prefixArray[j] = i+1;
            i++;
        }
        j++;
    }
    i = j = 0;
    uint16_t foundAt = i;

    while(j<patternLength && i<stringLength){
        if(str[i] == pattern[j]){
            i++; j++;
        }else{
            while(j >= 0){
                if(pattern[prefixArray[j-1]] == str[i]){
                    i++; j = prefixArray[j-1]+1; break;
                }
                if(j == 0){
                    i++; break;
                }
                j--;
            } foundAt = i;
        }
    }
    bool isFound = j == patternLength;
    if(isFound) cout<<"Pattern found at index = "<<foundAt<<endl;
    return isFound;
}

int main(){
    char str[] = "MAHABHARAT KATHA"; //"ABABDABACDABABCABAB";
    char pattern[] = "BHARAT"; //"ABABCABAB";
    uint16_t n1 = sizeof(str)/sizeof(char)-1;
    uint16_t n2 = sizeof(pattern)/sizeof(char)-1;
    if(isSubString(str, pattern, n1, n2))
        cout<<pattern<<" is a substring of "<<str<<endl;
    else cout<<pattern<<" is not a substring of "<<str<<endl;
    return 0;
}

/*Output
Pattern found at index = 4
BHARAT is a substring of MAHABHARAT KATHA
*/