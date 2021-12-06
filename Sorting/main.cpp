#include<BigInt.h>
#include<Sorting.h>
#define SIZE 8

int main(){
    BigInt x[SIZE]={BigInt("592"),BigInt("-092"),BigInt("555"),BigInt("-123"),BigInt("432"),BigInt("234"),BigInt("120"),BigInt("110")};
    BigInt a=x[0]-x[1]-x[2];
    cout<<a.GetString()<<endl;

    //Quick_SORT::ASCENDING::SORT(x,0,SIZE-1);
    Merge_SORT::DESCENDING::SORT(x,0,SIZE-1);

    for(int i=0;i<SIZE;i++) cout<<x[i].GetString()<<" "; cout<<endl;
    return 0;
}
