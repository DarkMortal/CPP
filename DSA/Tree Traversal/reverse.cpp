#include "./tree.hpp"

void reverse(Node* node){
	// base condition
	if (node == NULL) return;

	// First recur on left child
	reverse(node->left);

	// Now recur on right child
	reverse(node->right);

    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

int main(){

	// defining the tree
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

    reverse(root);
    printPreorder(root);
    cout << endl;

    return 0;
}