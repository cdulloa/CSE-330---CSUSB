#include "BinaryHeap.cpp"

int main() 
{
    // declare instance of Binary Heap; suitable to hold a queue of print jobs.
    BinaryHeap<int> printQueue;

    int numJobs = 9;
    int priority;
    // Prompt user to enter a sequence of priority values of print jobs
    for (int i = 0; i < numJobs; i++) 
    {
        cout << "The priority of print job? ";
        cin >> priority;
        // insert these print jobs into the printQueue.
        printQueue.insert(priority);
    }

    // print out jobs
    cout << endl; 
    printQueue.printJobs();
    cout << endl; 

    // Prompts user to enter n - the number of jobs that the printer will run.
    cout << "The number of jobs the printer will run? ";
    int n;
    cin >> n;

    // Calls deleteMin() member function n times. 
    for (int i = 0; i < n; i++) 
    {
        printQueue.deleteMin();
    }

    // print out the remaining print jobs
    cout << endl; 
    printQueue.printJobs();

    return 0;
}
