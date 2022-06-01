#include "Employee.cpp"
#include "DoublyLinkedQueue.cpp"

int main() 
{
    int num;
    string letter;
    int k;

    //declares a queue which stores int values
    Queue<int> queueInteger;
    //prompts users to enter integers
    cout << "Enqueue positive numbers (Enter -1 to stop): \n";
    do 
    { 
        cin >> num;
        if (num == -1) 
        {
            break;
        }

        queueInteger.enqueue(num);
    } while (true);

    cout << "print queue: ";
    queueInteger.print(); 

    // Prompts the user to enter a number k
    cout << "How many numbers to be removed from queue: ";
    cin >> k;
   
    //dequeues k values from the front of the queue. 
    while (k-- > 0 && !queueInteger.empty()) 
    {
        queueInteger.dequeue();
    }
    cout << "print queue: ";
    queueInteger.print(); 
    cout << endl;


    // declares a queue which stores strings
    Queue<string> queueString;
    
    cout << "Enqueue string (enter exit to stop): \n";
    // enqueue the entered strings, stops entering the strings when the user enter "exit". 
    do 
    {
        
        cin >> letter;
        if (letter == "exit") 
        {
            break;
        }

        queueString.enqueue(letter);
    } while (true);

    cout << "print queue: ";
    queueString.print(); 

    cout << "How many strings to be removed from queue : ";
    cin >> k;

    // dequeues k strings from the front of the queue. 
    while (k-- > 0 && !queueString.empty()) 
    {
        queueString.dequeue();
    }
   
    cout << "print queue: ";
    queueString.print(); 
    cout << endl;


    // declares a queue which stores employess
    Queue<Employee> queueEmployee;

    string employeeName;
    int employeeId;
    string employeeDept;
    
    
    do 
    {
       //Prompts users to enter employee's name, id, and department name
        cout << "Enqueue employee's name, id. dept (enter id 0 to stop): ";
        cin >> employeeName >> employeeId >> employeeDept;
        
        if (employeeId == 0) 
        {
            break;
        }

        Employee employeeObj(employeeName, employeeId, employeeDept);

        queueEmployee.enqueue(employeeObj);
    } while (true);

    cout << "print queue:  ";
    queueEmployee.print(); 
    //Prompts users to enter a number k 
    cout << "How many strings to be removed from queue: ";
    cin >> k;
   
    //and dequeues k employees from the front of the queue.
    while (k-- > 0 && !queueString.empty()) 
    {
        queueEmployee.dequeue();
    }

    cout << "print queue: ";
    queueEmployee.print(); 
}
