#include<BigInt.h>
#include<vector>
#include<algorithm>

int main(){
    vector<BigInt> x={BigInt("592"),BigInt("-092"),BigInt("555"),BigInt("-123"),BigInt("432"),
                    BigInt("234"),BigInt("120"),BigInt("110"),BigInt("85"),BigInt("-54")};
    for(BigInt i:x) cout<<i.GetString()<<" ";
    std::sort(x.begin(),x.end()); cout<<endl;
    for(BigInt i:x) cout<<i.GetString()<<" ";
    return 0;
}
