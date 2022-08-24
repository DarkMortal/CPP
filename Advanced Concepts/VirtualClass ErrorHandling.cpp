#include <iostream>
using namespace std;

class Person{
    protected:  string name;
                uint16_t gender;
    public: Person(){ throw string("Empty string Literals not Allowed"); }
            // noexcept = can't throw exceptions
            Person(string str,uint16_t x) noexcept : name(str), gender(x) {
                cout<<"A Person is Born"<<endl;
            }
            virtual void Disp() const = 0; //Pure Virtual Function
};

class Warrior :public Person{
    uint32_t powerLevel;
    public: Warrior(string name,uint16_t x,uint32_t y) noexcept : Person(name,x), powerLevel(y) {
        cout<<"A warrior is born !!!"<<endl;
    }
    Warrior() = default;
    void Disp() const{
        cout<<"\nName : "<<this->name<<endl;
        cout<<"Gender : "<<((this->gender > 0)?"Male\n":"Female\n");
        cout<<"Power Level = "<<this->powerLevel<<endl;
    }
};

int main(){
    try{
        Warrior x("Gogeta",1,9000);
        x.Disp();
        Warrior y;
    }catch(string err){
        cout<<"\nHandled Error :\n"<<err<<endl;
    }catch(...){
        cout<<"\nSome unknown Error"<<endl;
    }
}

/*Output
A Person is Born
A warrior is born !!!

Name : Gogeta
Gender : Male
Power Level = 9000

Handled Error :
Empty string Literals not Allowed
*/