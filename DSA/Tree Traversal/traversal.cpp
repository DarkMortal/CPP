#include "./tree.hpp"

int main(){

	// defining the tree
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	// Function call
	cout << "Inorder traversal:\n";
	printInorder(root);
    cout << endl << endl;

	cout << "Preorder traversal:\n";
	printPreorder(root);
    cout << endl << endl;

	cout << "Postorder traversal:\n";
	printPostorder(root);
    cout << endl;

	// don't forget to dellocate memory :)
	dealloc(root);

	return 0;
}
