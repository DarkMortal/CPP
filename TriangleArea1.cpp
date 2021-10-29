#include<iostream>

float MOD(float x){
    if(x>=0) return x;
    else return x*(-1);
}

float DET(float x[3][3]){
    float a= x[0][0]*(x[1][1]*x[2][2]-x[1][2]*x[2][1]);
    float b= x[1][0]*(x[0][1]*x[2][2]-x[2][1]*x[0][2]);
    float c= x[2][0]*(x[0][1]*x[1][2]-x[1][1]*x[0][2]);
    return MOD(a-b+c);
}

int main(){
    float matrix[3][3];
    std::cout<<"Enter the coordinates of the 3 points 1 by 1: "<<std::endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<2;j++) std::cin>>matrix[i][j];
        matrix[i][2]=1;
    }
    std::cout<<std::endl<<"Area of the Triangle = "<<DET(matrix)/2<<" sq. units"<<std::endl;
    return 0;
}
