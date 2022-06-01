#include <iostream>
#include "LinkedList.cpp"
#include "Employee.cpp"
using namespace std;
int main() 
{
    int v, k;

    LinkedList<int> L;
    cout << "Create a List of Integers:" << endl;
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        L.push_front(n);
    }
    cout << "The size of linked list is:" << L.get_size() << endl;
    cout << "The LinkedList is:" << endl;
    L.print();
    
    cout << "Enter the key:";
    cin >> v;
    cout << "Is the key in the list?" << L.find(v) << endl;
    cout << "How many values you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        L.pop_front();
    }
    cout << "The List is:" << endl;
    L.print();
    cout << endl << endl;

    LinkedList<string> S;
    cout << "Create a List of strings:" << endl;
    while (1)
    {
        string n;
        cin >> n;
        if (n == "exit")
        {
            break;
        }
        S.push_front(n);
    }
    cout << "The size of linked list is:" << S.get_size() << endl;
    cout << "The LinkedList is:" << endl;
    S.print();
    string si;
    cout << "How many values you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        S.pop_front();
    }
    cout << "The List is:" << endl;
    S.print();
    cout << endl << endl;


    LinkedList <Employee> list;
    string name;
    int id;
    string dept;
    cout << "Create a list of employees:" << endl;
    while (1)
    {
      cout << "Enqueue employee name, id, dept(enter id 0 to stop): ";
      cin >> name >> id >> dept;
        if (id == 0)
        {
            break;
        }
        Employee newEmployee(name, id, dept);
        list.push_front(newEmployee);
    }
    cout << "The size of linked list is:" << list.get_size() << endl;
    cout << "The linked list is: " << endl;
    list.print();

    cout << "How many values you want to remove? ";
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        list.pop_front();
    }
    cout << "The linked List is:" << endl;
    list.print();

    return 0;
}
