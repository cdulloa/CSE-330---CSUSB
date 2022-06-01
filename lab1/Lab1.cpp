#include "Student.cpp"
#include<iostream>
#include<string>
#include "Student.cpp"
using namespace std;
int main() {
    /*VARIABLE DECLARATION */
    int n, i, id;
    string name;
    /*READ NUMBER OD STUDENTS*/
    cout << "Enter the capacity of dynamic array : ";
    cin >> n;
    /*DECLARE A POINTER TO STUDENTS CLASS*/
    Student* groups;
    /*ALLOCATE THE MEMORY FOR 'N' OBJECTS*/
    groups = new Student[n];
    for (i = 0; i < n; i++) {
        /*READ STUDENT ID*/
        cout << "Enter Student ID : ";
        cin >> id;
        /*BREAK ID USER ENTER 0*/
        if (id == 0)
            break;
        /*READ THE STUDENT NAME*/
        cout << "Enter Student Name : ";
        cin >> name;
        /*CREATE STUDENT CLASS OBJECT*/
        Student newStudent(id, name);
        /*STORE THE OBJECT IN THE ARRAY*/
        groups[i] = newStudent;
    }
    /*IF THE USER MAY EXIT BEFORE 'N' */
    n = i;
    /*DISPLAY STUDENT DATA */
    cout << "\nThe Studetns are :" << endl;
    for (i = 0; i < n; i++) {
        groups[i].print_student();
    }
}