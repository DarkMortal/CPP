#include<iostream>
using namespace std;

int main(){
    int n = 0;

    cout<<"Enter number of Variables : "; cin>>n;
    double arr[n][3], b[n];

    cout<<"Enter Matrix A :\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin>>arr[i][j];
    }

    cout<<"Enter Matrix B :\n";
    for(int i=0;i<n;i++) cin>>b[i];

    //TODO: Calculate the last root
    double den = arr[0][0];
    double temp = b[0];

    for(int i=1;i<n-1;i++){
        temp /= den;
        int diagup = (i == 1)?1:2;
        den = arr[i][1] - arr[i-1][diagup]*arr[i][0]/den;
        temp = b[i] - temp*arr[i][0];
    }
    temp /= den;
    temp = b[n-1] - temp*arr[n-1][1];  //Value of Last R(n)

    den = arr[n-1][2] - arr[n-2][2]*arr[n-1][1]/den;

    //TODO: Back Substitution
    double lastVar2 = temp/den, lastVar = (b[n-1]-lastVar2*arr[n-1][2])/arr[n-1][1];

    cout<<"The Roots are :\nVar_"<<n<<" = "<<lastVar2<<endl<<"Var_"<<n-1<<" = "<<lastVar<<endl;

    for(int i=n-2;i>0;i--){
        double sum = arr[i][1]*lastVar + arr[i][2]*lastVar2,
            newRoot = (b[i] - sum)/arr[i][0];
        cout<<"Var_"<<i<<" = "<<newRoot<<endl;
        lastVar2 = lastVar;
        lastVar = newRoot;
    }

    return 0;
}
