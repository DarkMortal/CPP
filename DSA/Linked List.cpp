#include<iostream>
using namespace std;

struct Node{
    int index;
    string name;
    Node* next=NULL;
    Node* previous=NULL;
    Node(string str,int a=0):index(a),name(str){}
    void Display(){ cout<<index<<" : "<<name<<endl; }
} start("",1);

//Driver CODE
int main(){
    int n=0;   //Number of Elements of the List
    cout<<"Enter the number of Names : "; cin>>n;
    if(n<4) cout<<"Number of Names must be greater than 3"<<endl;
    else {
        string input="";
        cout<<"Enter the Names : "<<endl; getchar();

        //Initialising the List
        getline(cin,input);
        start.name=input;
        Node* current=&start;

        //Initialising rest of the Elements
        for(int i=1;i<n;i++){ 
            getline(cin,input);
            current->next=new Node(input,i+1);
            current->next->previous=current;
            current=current->next;
        }
        cout<<endl;

        //Displaying all the elements
        Node* temp=&start;
        while(temp){
            temp->Display();
            temp=temp->next;
        }

        //Let's say we want to delete third second element. So we set n=3
        n=3;
        temp=&start;
        for(int i=1;i<n;i++) temp=temp->next;
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;
        delete temp;

        cout<<"\nAfter deleting the third Element"<<endl;
        //Displaying the values and deallocating memory
        do{
            if(current==&start){
                current->Display(); 
                delete current; break;
            }
            else if(current){
                temp=current->previous;
                current->Display();
                delete current;
                current=temp;
            }
        }while(current->previous || current==&start);
    } return 0;
}
