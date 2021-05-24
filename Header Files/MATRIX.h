#include<iostream>
using namespace std;
template <class X>
int MatCmp(X x[10][10],X y[10][10],int row,int column){
    int temp=0;
     for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(x[i][j]==y[i][j])
                temp++;
            else break;
     }} if(temp==row*column)
        return 1;
     else return 0;
}
template <class X>
void GetMat(int row,int column,X A[10][10]){
   for(int i=0;i<row;i++){
      for(int j=0;j<column;j++)
      cin>>A[i][j];
}}
template <class X>
void DispMat(int row,int column,X A[10][10]){
   for(int i=0;i<row;i++){
      for(int j=0;j<column;j++){
      	if(A[i][j]==0) cout<<0<<" ";
      else cout<<fixed<<A[i][j]<<" "; }
      cout<<endl;
}}
template <class X>
void MatCpy(X x[10][10],X y[10][10],int row,int column){
      for(int i=0;i<row;i++){
        for(int j=0;j<column;j++)
            y[i][j]=x[i][j];
}}
template <class X>
void Transpose(X A[10][10],X B[10][10],int row,int column){
   for(int i=0;i<row;i++){
       for(int j=0;j<column;j++)
       B[column-j][i]=A[i][column-j];}
   for(int i=0;i<row;i++){
       B[0][i]=A[i][0];
}}
template <class X>
void MatMul(X A[10][10],X B[10][10],X C[10][10],int r1,int r2,int c2){
  int sum=0;
  for(int k=0;k<c2;k++){
     for(int i=0;i<r1;i++){
	for(int j=0;j<r2;j++)
	sum=sum+A[i][j]*B[j][k];
    C[i][k]=sum;
    sum=0;
 }} }
 template <class X>
 void MatInt(X x[10][10],int row,int column,float num){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++)
            x[i][j]=num*x[i][j];
}}
template <class X>
X MOD(X x[][10],int b){
  X p;
  if(b==2)
    p=(x[0][0]*x[1][1]-x[1][0]*x[0][1]);
  else if(b==3){
  X a,b,c;
  a= x[0][0]*(x[1][1]*x[2][2]-x[1][2]*x[2][1]);
  b= x[1][0]*(x[0][1]*x[2][2]-x[2][1]*x[0][2]);
  c= x[2][0]*(x[0][1]*x[1][2]-x[1][1]*x[0][2]);
  p=(a-b+c);
} return p;}
template <class X>
void ADJ(X a[10][10],X b[10][10],int size){
  if(size==2){
  b[0][0]=a[1][1];
  b[0][1]=-a[0][1];
  b[1][0]=-a[1][0];
  b[1][1]=a[0][0];
} else if(size==3){
  X x[3][3]; 
  x[0][0]= a[1][1]*a[2][2]-a[1][2]*a[2][1];
  x[1][0]= -1*(a[0][1]*a[2][2]-a[2][1]*a[0][2]);
  x[2][0]= a[0][1]*a[1][2]-a[1][1]*a[0][2];
  
  x[0][1]= -1*(a[1][0]*a[2][2]-a[1][2]*a[2][0]);
  x[1][1]= a[0][0]*a[2][2]-a[0][2]*a[2][0];
  x[2][1]= -1*(a[0][0]*a[1][2]-a[0][2]*a[1][0]);
  
  x[0][2]= a[1][0]*a[2][1]-a[1][1]*a[2][0];
  x[1][2]= -1*(a[0][0]*a[2][1]-a[0][1]*a[2][0]);
  x[2][2]= a[0][0]*a[1][1]-a[0][1]*a[1][0];
  
  for(int i=0;i<3;i++){
       for(int j=0;j<3;j++)
       b[3-j][i]=x[i][3-j];}
   for(int i=0;i<3;i++){
       b[0][i]=x[i][0];
}}}
template <class X>
X ABS(X x){
	if(x>0) return x;
	if(x<0) return (x*(-1));
}

