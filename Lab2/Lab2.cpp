#include "Student.cpp"
#include<string>

#include<iostream>

using namespace std;

int main()
{

	int id = -1;
	string name;
	NodeType* team = nullptr;

	while (id != 0)

	{

       		cout << "Enter the student id: ";
		cin >> id;

		if (id == 0)

			break;

		cout << "Enter the student name: ";
		cin >> name;
		Student newStudent(id, name);
		NodeType* pointer = new NodeType(newStudent);
		pointer -> next = team;
		team = pointer;
		cout << "The student is added" << endl << endl;

	}

	cout << endl;

	cout << "Here is the list of student";
	NodeType* ptr = team;
	while(ptr != nullptr){
		ptr -> student.print_student();
		ptr = ptr -> next;
	}

	cout << endl << "THe student id to be removed: ";
	cin >> id;

	NodeType* previous = team;
	NodeType* current = nullptr;
	if(team -> student.get_id() == id){
		team = team-> next;
		delete previous;
	}
	else{
		while((previous-> next != nullptr) && (previous -> next -> student.get_id() != id)){
			previous = previous-> next;
	

		}
		if(previous-> next != nullptr){

			current = previous-> next;
			previous-> next = current-> next;
			delete current;


		}


	}
	cout << endl;

	cout << "Here is the list of student";
        ptr  = team;
        while(ptr != nullptr){
                ptr -> student.print_student();
                ptr = ptr -> next;
          }


	return 0;

}
