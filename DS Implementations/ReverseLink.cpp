#include <bits/stdc++.h>
using namespace std;

// printng a linkedlist in reverse without actually reversing it

// Node structure
struct Node{
    uint16_t value;
    Node *next;
    ~Node(){ delete next; }  // destructor function
    Node(uint16_t &x, Node *p = NULL) : value(x), next(p) {}  // l-value reference
    Node(uint16_t &&x, Node *p = NULL) : value(x), next(p) {} // r-value reference
};

void printForward(Node &head){
    Node *p = &head;
    while (p){
        cout << p->value << " ";
        p = p->next;
    } cout << endl;
}

void printReverse(Node *head){
    if (head == NULL)
        return;
    printReverse(head->next);
    cout << head->value << " ";
}

int main(){
    Node list = {7};
    Node *currentNode = &list;

    // function to add a value to list
    auto addToList = [&](uint16_t x) -> void
    {
        currentNode->next = new Node(x);
        currentNode = currentNode->next;
    };

    uint16_t arr[] = {9, 11, 12, 14, 17, 19};
    uint16_t n = sizeof(arr) / sizeof(uint16_t);

    // add all elements of array to list
    for (int i = 0; i < n; i++)
        addToList(arr[i]);

    // displaying the list
    printForward(list);
    printReverse(&list);

    cout << endl;
    return 0;
}

/* Output
7 9 11 12 14 17 19 
19 17 14 12 11 9 7
*/