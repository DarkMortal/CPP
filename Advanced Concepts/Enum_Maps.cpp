#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
typedef std::unordered_map<char,string> data;
using power=std::map<char,int>;

data stark={
   {
       'a',"Alligator"
   },
   {
       'b',"Baseball"
   },
   {
       'n',"Niggachu"
   }
};

union PowerUp{
   char type;
   int powerLevel;
};

power List={
    {
        'A',10000
    },
    {
        'B',9000
    },
    {
        'C',7000
    },
    {
        'D',5000
    },
    {
        'E',2000
    }
};

enum Saiyans:unsigned int{
   Goku=1,Vegeta,Broly,Rycon
};

int main(){
   stark['p']="Ping Pong";
   stark['c']="Catastrophe";
   stark.insert(pair<char,string>('d',"Discus Throw"));
   stark.insert(pair<char,string>('e',"Elephant"));
   for(data::iterator i=stark.begin();i!=stark.end();i++) cout<<i->first<<" : "<<i->second<<endl;
   PowerUp x,y;
   x.powerLevel=List['A'];
   y.type='A';
   cout<<endl<<x.powerLevel<<"  "<<y.powerLevel<<endl;
   cout<<Broly<<endl;
   return 0;
}
