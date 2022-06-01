#include"bst.cpp"

int main() 
{
    //Declares an instance of BinarySearchTree 
    //(short: BST) suitable to hold integer values. 
    BinarySearchTree<int> bst;
    int val;
    int   k1;
    int   k2;

    cout << "insert the values (stop when entering 0) :\n";
    while (1) 
    {
        cin >> val;
        if (val == 0) break;
        bst.insert(val);
    }
    bst.printBST(); //Calls the printBST() member function to print out the values of the BST structure. 

    cout << "\n\nPlease enter the range: ";
    cin >> k1 >> k2;
    cout << "Print the element between the range:\n";
    bst.printRange(k1, k2);

    cout << "\n\nremove the values (stop when entering 0) :\n";
    while (1) 
    {
        cin >> val;
        if (val == 0) break;
        bst.remove(val);
    }
    bst.printBST();
}
