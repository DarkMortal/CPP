#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

namespace number_system{
	int precision=5;

	double Binary2Decimal(string x){
	  double sum=0,len2=x.length();
	  string s2(x.begin(), find(x.begin(), x.end(), '.')),s3="";
	  int len=s2.length();
	  for(int i=len;i>0;i--)
	     if((x.at(i-1)-48)==1) sum=sum+pow(2,len-i);
	  if(x!=s2){
	    s3=x.substr(len+1,len2);
	    int len3=s3.length();
	    for(int j=0;j<len3;j++)
	       if((s3.at(j)-48)==1) sum=sum+pow(2,-1-j);
	  }
	  return sum;
	}

	string Binary2Octal(string x){
	  string temp="",bres="",ares="";
	  string beforeDECIMAL="",afterDECIMAL="";
	  int sum=0,len2=0,req=0;

	  //Finding the Decimal
	  int a=x.find(".");

	  //If Decimal found
	  if(a!=string::npos){
	    beforeDECIMAL=x.substr(0,a);
	    afterDECIMAL=x.substr(a+1,x.length());

	      //Before Decimal calculation
	      req=beforeDECIMAL.length()%3;
	      if(req!=0){
		 for(int i=0;i<(3-req);i++) temp=temp+"0";
		 cout<<temp<<endl;
		 temp=temp+beforeDECIMAL;
	      }
	      len2=temp.length();
	      for(int i=0;i<len2;i+=3){
		sum=Binary2Decimal(temp.substr(i,i+3));
		bres=bres+to_string(sum);
	      }

	      temp.clear(); temp="";  //Clearing the string

	      //After Decimal calculation
	      req=afterDECIMAL.length()%3;
	      if(req!=0){
		 for(int i=0;i<(3-req);i++) temp=temp+"0";
		 temp=afterDECIMAL+temp;
	      }
	      len2=temp.length();
	      for(int i=0;i<len2;i+=3){
		sum=Binary2Decimal(temp.substr(i,i+3));
		ares=ares+to_string(sum);
	      }
	      return (bres+"."+ares);
	    }

	  else{
	      req=x.length()%3;
	      if(req!=0){
		 for(int i=0;i<(3-req);i++) temp=temp+"0";
		 temp=temp+x;
	      }
	      len2=temp.length();
	      for(int i=0;i<len2;i+=3){
		sum=Binary2Decimal(temp.substr(i,i+3));
		bres=bres+to_string(sum);
	      }
	      return bres;
	  }

	}

	double exp_multiple(double x,int n){
	   string str=to_string(x);
	   double decm=0;
	   int s=str.find(".");
	   if(s!=string::npos){
	      decm=stod(str.substr(s,str.length()));
	      return (decm*n);
	   }
	   else if(x==0) return 0;
	   else return 0;
	}

	string DecimalConversion(double d,int n){
	   string res="",dec="";
	   double decm=0;
	   int a=d,rem=0,cnt=0;
	   if(a==0) res="0";
	   while(a){
	     rem=a%n;
	     if(n==16 && rem>9) res=res+char(rem+55);
	     else res=res+char(rem+48);
	     a=a/n;
	   }
	   reverse(res.begin(),res.end());
	   decm=exp_multiple(d,n);
	   if(decm==0) return res;
	   else{
	      while(cnt<precision && decm!=0){
		if(n==16 && (int)decm>9) dec=dec+char(decm+55);
		else dec=dec+char(decm+48);
		decm=exp_multiple(decm,n);
		cnt++;
	      }
	      return (res+"."+dec);
	   }
	}

	string Decimal2Hexadecimal(double n){
	   return DecimalConversion(n,16);
	}

	string Decimal2Binary(double d){
	   return DecimalConversion(d,2);
	}

	string Decimal2Octal(double d){
	   return DecimalConversion(d,8);
	}

	double Decimal2OctalNUMERIC(double d){
	   return stod(DecimalConversion(d,8));  //stod is used to convert int,float & double to std::string
	}

	double Binary2OctalNUMERIC(string x){
	   return stod(Binary2Octal(x));
	}
}

int intrev(int x){
  string str=to_string(x);
  reverse(str.begin(),str.end());
  return stof(str);
}

int digsum(int x){
  int sum=0;
  while(x){
    sum=sum+(x%10);
    x=x/10;
  }
  return sum;
}

char* strrev(char *str)
{
      char *p1, *p2;
      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
