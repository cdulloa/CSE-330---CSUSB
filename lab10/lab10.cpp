#include <iostream>

#include <vector>
#include "bst.cpp"
#include "MergeSort.cpp"
#include <fstream>
using namespace std;

int main()
{
	// declares a vector which can store a collection of integers. 
	vector<int> vect;
	// declares a binary search tree instance which can store 
	//a collection of integers. 
	BinarySearchTree<int> tree;

	// open the file
	ifstream input("sort.txt"); 

		int number;

		while (input >> number)
		{
			
			vect.push_back(number); // insert the integer into the vector 
			tree.insert(number); // insert the data into the created binary search tree. 
		}
		input.close(); 

		mergeSort(vect); // sort the elemnts in the vector
		// prints the sorted vector
		cout << "The merge sort: ";
		for (size_t i = 0; i < vect.size(); i++)
		{
			cout << vect[i] << " ";
		}

		// prints elements in binary search tree
		cout << endl;
		cout << "The tree sort: ";
		tree.printBST(); // to print the elements in the binary search tree 
		cout << endl;
	
	return 0;
}
