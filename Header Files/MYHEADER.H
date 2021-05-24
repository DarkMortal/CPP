#include<iostream>
#include<math.h>
#include<cmath>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;
void intrev(int &x){
int i=0,y[100],sum=0;
   do{
   y[i]=x%10;
   x=x/10;i++;
   }while(x>0);
   i--;
   for(int j=0;j<=i;j++){
   sum=sum+y[j]*pow(10,(i-j));
   }
   x=sum;
}
int fact(int x)
{
   if(x==0)
   return 1;
   else
 {
   int p=1;
   for(int i=0;i<x;i++)
   {
      p=p*(x-i);
   }
   return p;
 }
}

long int combine(int x,int y)
{
   int a=fact(x),b=fact(y),c=fact(x-y),z;
   z=a/(b*c);
   return z;
}

void intrev(long int &x){
int i=0,y[100];long int sum=0;
   do{
   y[i]=x%10;
   x=x/10;i++;
   }while(x>0);
   i--;
   for(int j=0;j<=i;j++){
   sum=sum+y[j]*pow(10,(i-j));
   }
   x=sum;
}

long int permute(int x,int y)
{
   int a=fact(x),b=fact(x-y),z;
   z=a/b;
   return z;
}

int digitno(long int x)
{
long int y,z=0;
   while(x>0)
   {
     y=x/10;
     x=y;
     z++;
   }
   return z;
}

int factsum(int x)
{
   int z=0;
   for(long int i=1;i<=x;i++)
      {
            if(x%i==0)
	{
	     z=z+i;
	}
       }
           return z;
}

int HCF(int x,int y)
{
    while(x!=y)
   {
     if(x>y)
     x=x-y;
     else
     y=y-x;
   }
   return x;
}

int LCM(int x,int y)
{
    int z,p;
    z=HCF(x,y);
    p=(x*y)/z;
    return p;
}

void swap(int &x,int &y){
   x=x+y;
   y=x-y;x=x-y;
}

bool isPrime(int n){
	for(int i=1;i<=(n/2);i++){
		if(n%i==0){
			if(i!=1&&i!=n) return false;
		}
	}
	return true;
}

int RAND(int LOW,int HIGH){
	int TEMP=(HIGH-LOW+1);
	return (rand()%TEMP)+LOW;
}

int greatdigit(long n){
 int i=0,x[100],sum=0,m=0;
   do{x[i]=n%10;
   n=n/10; i++;sum=sum+1;
   }while(n>0);
   for(i=0;i<sum;i++){
     if(m<x[i])
     m=x[i];} return m;}

int digisum(long int x){
 int y[100],sum=0,i=0;
   do{
   y[i]=x%10;
   x=x/10;
   sum=sum+y[i];
   }while(x>0);
  return sum;
}

void Ascending(int x[],int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<(n-1);j++){
       if(x[j]>x[j+1])
       swap(x[j],x[j+1]);
  }  }}

void Descending(int x[],int n){
    for(int i=0;i<n;i++){
    for(int j=0;j<(n-1);j++){
       if(x[j]<x[j+1])
       swap(x[j],x[j+1]);
  }  }}

void Int_String(int num,char x[]){
	int i=0;
	while(num>0){
		x[i]=char(num%10 + 48);
		i++; num=num/10;
	} strrev(x);
}
int String_Int(char x[]){
	int s,sum=0;
	for(int i=0;i<strlen(x);i++){
		s=int(x[i])-48;
		sum=sum+s*pow(10,i);
	}  intrev(sum);
	return sum;
}
void rem(char x[100],char y){
	for(int i=0;i<strlen(x);i++){
		if(x[i]==y){
			for(int j=i;j<strlen(x);j++)
			x[j]=x[j+1];
		}
}}
void passen(char pass[]){
  int i = 0; char a;
    for(i=0;;)
    {
        a=_getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            pass[i]=a; i++; cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b"; i--; }
        if(a=='\r')
        { pass[i]='\0'; break;
}}}
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
  }
int wherex()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.X;
}
int wherey()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwCursorPosition.Y;
}

template<class X>
X ABS(X x){
	if(x>0) return x;
	else if(x<0) return -x;
}

double Integral(float a,float b,double(*Calc)(double)){
	const int n=30;
	float h,sum=0.0; double res;
	float x[n],y[n];
	h=(b-a)/n;
	for(int j=0;j<n+1;j++){
		x[j]=a+j*h;
		y[j]=Calc(x[j]);
	}
	for (int i=1;i<n;i+=2)  sum=sum+4.0*y[i];
    for (int i=2;i<n-1;i+=2) sum=sum+2.0*y[i];
	sum=sum+y[0]+y[n];
	res=sum*(h/3.0);
	return res;
}
