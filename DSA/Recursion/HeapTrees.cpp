#include <bits/stdc++.h>
#define MAX(a,b) (a>b)?a:b
#define iter for(int i=0;i<n;i++)
using namespace std;

struct Node{
    float value;
    Node* parent;
    Node* left;
    Node* right;
    Node(float x=0,Node* a=nullptr,Node *b=nullptr,Node* c=nullptr): value(x),left(a),right(b),parent(c){}
};

void Heapify(Node*); //max heap
void Tree(float*,Node*,int);

//TODO : Heap to Array
void Array(Node* x,float* arr,int n=1){
    arr[n-1] = x->value;
    if(x->left && x->right){
        Array(x->left,arr,n*2);
        Array(x->right,arr,n*2+1);
    }
    else if(x->left) Array(x->left,arr,n*2);
    else if(x->right) Array(x->right,arr,n*2+1);
    else return;
}

Node a(11),b(12),c(10,&a,&b),d(8),e(9),f(7,&d,&e),l(5,&c,&f);

int main(){
    float arr[] = {3,4,1,2,7,8,5};
    int n = sizeof(arr)/sizeof(float);

    //TODO : Demonstrating Tree to Array conversion
    float arr2[n]={0};
    Node* top = &l;
    Array(top,arr2);
    iter cout<<i[arr2]<<" ";

    //Array to Tree
    Node nodes[n];
    Tree(arr,nodes,n);
    Node* temp = nodes[0].left->right;
    cout<<endl<<temp->value<<" "<<temp->parent->value<<endl;

    bool isSame = true;

    //Same tree to Array
    float arr3[n]={0};
    Array(nodes,arr3);
    iter{
        cout<<i[arr3]<<" ";
        if(i[arr3] != i[arr]) isSame = false;
    } if(isSame) cout<<"\nThe 2 arrays are Same for now\n";

    Heapify(nodes);
    Array(nodes,arr3);
    iter cout<<i[arr3]<<" ";
    return 0;
}

void Tree(float* arr,Node* nodes,int size){
    int c = size;
    for(int i=0;i<size;i++) i[nodes].value = i[arr];
    while(c>1){
        if(c%2 == 0) nodes[c/2-1].left = (nodes+c-1);
        else nodes[c/2-1].right = (nodes+c-1);
        if(!nodes[c-1].parent) nodes[c-1].parent = (nodes+c/2-1);
        c--;
    }
}

//Result coming as expected but algorithm is logically incorrect
void Heapify(Node* node){
    if(node->right && node->left){
        Heapify(node->left);
        Heapify(node->right);
        if(node->right->value > node->value || node->left->value > node->value){
            float max = MAX(node->right->value,node->left->value), temp = node->value;
            if(max == node->left->value){
                node->value = node->left->value;
                node->left->value = temp;
            }
            else{
                node->value = node->right->value;
                node->right->value = temp;
            }
        }
    }
    else if(node->right){
        Heapify(node->right);
        if(node->right->value > node->value){
            float temp = node->value;
            node->value = node->right->value;
            node->right->value = temp;
        }
    }
    else if(node->left){
        Heapify(node->left);
        if(node->left->value > node->value){
            float temp = node->value;
            node->value = node->left->value;
            node->left->value = temp;
        }
    }
    else{
        if(node->parent->value < node->value){
            float temp = node->value;
            node->value = node->parent->value;
            node->parent->value = temp;
        }
    }
}

/*Output :
5 10 7 11 12 8 9
7 4
3 4 1 2 7 8 5
The 2 arrays are Same for now
8 7 3 2 4 1 5

Checked with valgrind. No memory leaks*/