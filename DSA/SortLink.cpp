#include <bits/stdc++.h>
using namespace std;

// Program to Sort and reverse linked list

struct Node{
    int16_t x;
    Node* prev;
    Node* next;
    Node(int16_t);
    // ~Node();
} start(0);

Node::Node(int16_t a):x(a){
    prev = nullptr;
    next = nullptr;
}

void disp(Node* p,bool isReverse){
    Node* t = p;
    if(isReverse){
        while(t->prev){
            cout<<t->x<<" ";
            t = t->prev;
        } cout<<t->x<<endl;
    }else{
        while(t->next){
            cout<<t->x<<" ";
            t = t->next;
        } cout<<t->x<<endl;
    }
}


// TODO: sort the linked list in ascending order
void sortAsc(Node* p){
    if(!p) return;
    Node* t1 = p;
    Node* t2 = p;
    while(t1->next){
        if(t2->x > t1->x) t2 = t1;
        t1 = t1->next;
    }
    if(t2->x > t1->x) t2 = t1;
    int16_t val = t2->x;
    t2->x = p->x;
    p->x = val;
    sortAsc(p->next);
}

// TODO: reverse the linked list
void reverse(Node* p){
    Node* prev = nullptr;
    Node* current = p;
    Node* next = p->next;

    while(next){
        current->next = prev;
        current->prev = next;
        
        current = next;
        next = current->next;
        prev = current->prev;
    }
    current->next = prev;
    current->prev = next;
}

int main(){
    int a = 0, n = 0;
    cout << "Enter Number of Integers : ";
    cin >> n; 
    Node* p = &start;
    for(uint16_t i=0;i<n;i++){
        cin>>a;
        if(i!=0){
            p->next = new Node(a);
            p->next->prev = p;
            p = p->next;
        }
        else p->x = a;
    }
    // sorting and display
    sortAsc(&start);
    disp(&start,false);

    // display sorted list in reverse
    reverse(&start);
    disp(p,false);

    // Note: since the value isReverse is set to false in both the function calls,
    // in both cases the linked list is displayed in forward-iterated fashion

    // Deallocate memory in linked list
    Node* c = p;
    while(c){
        Node* t = c->next;
        delete c;
        c = t;
    }

    return 0;
}

/* Output
Enter Number of Integers : 6
7 5 8 6 4 3
3 4 5 6 7 8
8 7 6 5 4 3
Checked with valgrind. No memory leaks*/