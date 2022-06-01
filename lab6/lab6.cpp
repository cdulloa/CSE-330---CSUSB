#include "treeTraversal.cpp"

BinaryNode<char>* create_binary_tree() 
{
	BinaryNode<char>* node_A = new BinaryNode<char>('A');
	BinaryNode<char>* node_B = new BinaryNode<char>('B');
	BinaryNode<char>* node_C = new BinaryNode<char>('C');
	BinaryNode<char>* node_D = new BinaryNode<char>('D');
	BinaryNode<char>* node_E = new BinaryNode<char>('E');

	node_A->left = node_B;
	node_A->right = node_C;
	node_B->left = node_D;
	node_B->right = node_E;

	return node_A;
}

BinaryNode<int>* create_binary_tree_int() 
{
	BinaryNode<int>* node_1 = new BinaryNode<int>(1);
	BinaryNode<int>* node_2 = new BinaryNode<int>(2);
	BinaryNode<int>* node_3 = new BinaryNode<int>(3);
	BinaryNode<int>* node_4 = new BinaryNode<int>(4);
	BinaryNode<int>* node_5 = new BinaryNode<int>(5);
	BinaryNode<int>* node_6 = new BinaryNode<int>(6);
	BinaryNode<int>* node_7 = new BinaryNode<int>(7);
	BinaryNode<int>* node_9 = new BinaryNode<int>(9);
	BinaryNode<int>* node_11 = new BinaryNode<int>(11);

	node_1-> left = node_7;
	node_1-> right = node_3;
	node_7-> left = node_2;
	node_7-> right = node_6;
	node_3-> right = node_9;
	node_6-> left = node_5;
	node_6-> right = node_11;
	node_9-> left = node_4;

	return node_1;
}

int main() {
	BinaryNode<char>* root = create_binary_tree();
	// calling three traversal functions to print elemnts
	cout << "preorder: ";
	preorder(root);
	cout << "\ninorder: ";
	inorder(root);
	cout << "\npostorder: ";
	postorder(root);


	BinaryNode<int>* root_int = create_binary_tree_int(); //elements are integers
	cout << "\n\npreorder: ";
	preorder(root_int);
	cout << "\ninorder: ";
	inorder(root_int);
	cout << "\npostorder: ";
	postorder(root_int);

	return 0;
}
