    #include<iostream>
    #include<fstream>
    #include<string.h>
    using namespace std;

    ofstream obj;
    ifstream ifobj;

    struct Student{
        char name[100],father[100],mother[100];
        //Note:- In file handling, std::string of C++ standard doesn't work. You have to use std::string(char *) of C standard
        int cls,roll;
        Student(){ cls=roll=0; }
        void GET(){
          cout<<"\nEnter Name:-"; cin.ignore( numeric_limits <streamsize> ::max(), '\n'); cin.getline(name,100);
          cout<<"Enter Father:-"; cin.getline(father,100);
          cout<<"Enter Mother:-"; cin.getline(mother,100);
          cout<<"Enter Class:-"; cin>>cls;
          cout<<"Enter Roll:-"; cin>>roll;
        }
        void write(){ obj.write((char*)this,sizeof(*this)); }
        void Disp(){
          cout<<"\nName:-"<<name<<endl;
          cout<<"Father's Name:-"<<father<<endl;
          cout<<"Mother's name:-"<<mother<<endl;
          cout<<"Class:-"<<cls<<endl;
          cout<<"Roll:-"<<roll<<endl;
        }
    };

    void ReadFile();
    int DeleteDATA(char name[]);

    int main(){
      try{
        int n; char ch,arg[100];
        cout<<"What do you want?"<<endl<<"1. Enter data"<<endl<<"2. Read Data"<<endl<<"3. Delete Record"<<endl;
        cin>>ch;
        switch(ch){
          case '1':{
            cout<<"Enter Number of Students="; cin>>n;
            if(n>0) { obj.open("Student2.dat",ios::app|ios::binary);}
            Student ST[n];
            for(int i=0;i<n;i++){
              ST[i].GET();
              ST[i].write();
            }
            obj.close(); cout<<"Writing objects successfull"<<endl;
            break;
          }
          case '2':{ ReadFile(); break; }
          case '3':{
                 cout<<"\nEnter Name:-"; cin.ignore( numeric_limits <streamsize> ::max(), '\n'); cin.getline(arg,100);
                 cout<<DeleteDATA(arg)<<" records has been successfully deleted"<<endl;
                 break;
              }
          default: { string error="Unlisted command not supported"; throw error; }
        }
      } catch(string err){
        cout<<endl<<err<<endl;
      }
      return 0;
    }

    void ReadFile(){
      ifobj.open("Student2.dat",ios::in|ios::binary);
      string error;
      Student x;
      if(ifobj){
        while(ifobj.read((char*)&x,sizeof(x))) x.Disp();
        ifobj.close();
      }
      else{
        error="Student data file not found";
        throw error;
      }
    }

    int DeleteDATA(char name[]){
      int fl1=0,fl2=0;
      ifobj.open("Student2.dat",ios::in|ios::binary);
      obj.open("temp.dat",ios::app|ios::binary);
      string error;
      Student x;
      if(ifobj){
        while(ifobj.read((char*)&x,sizeof(x))){
            if(strcmp(x.name,name)!=0){
              obj.write((char*)&x,sizeof(x));
              fl1++;
            }
            fl2++;
        }
         ifobj.close(); obj.close();
         remove("Student2.dat");
         rename("temp.dat","Student2.dat");
         return (fl2-fl1);
      }
      else{
        error="Student data file not found";
        throw error;
      }
    }
