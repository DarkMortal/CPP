#ifndef TREE
#define TREE

#include <bits/stdc++.h>
using namespace std;

struct Node {
	uint16_t value;
	struct Node *left, *right;
    Node(uint16_t&&);
};

// Defining the constructor
Node::Node(uint16_t&& data):value(data) {
	this->left = this->right = NULL;
}

void printInorder(Node* node){
	// base condition
	if (node == NULL) return;

	// First recur on left child
	printInorder(node->left);

	// Then print the data of node
	cout << node->value << " ";

	// Now recur on right child
	printInorder(node->right);
}

void printPreorder(Node* node){
	// base condition
	if (node == NULL) return;

	// Then print the data of node
	cout << node->value << " ";

	// First recur on left child
	printPreorder(node->left);

	// Now recur on right child
	printPreorder(node->right);
}

void printPostorder(Node* node){
	// base condition
	if (node == NULL) return;

	// First recur on left child
	printPostorder(node->left);

	// Now recur on right child
	printPostorder(node->right);

	// Then print the data of node
	cout << node->value << " ";
}

// deallocating memory using post-order traversal
void dealloc(Node* d){
	// base condition
	if (d == NULL) return;

	// First delete left child
	dealloc(d->left);

	// Now delete right child
	dealloc(d->right);

    // Then delete node
	delete d;
}

#endif