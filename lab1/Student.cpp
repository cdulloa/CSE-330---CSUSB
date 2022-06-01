#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<string>
using namespace std;

class Student 
{
public:
	
	//Student();
	//Student(int id, const string& name);
	//string get_name() const;
	//int get_id() const;
	//void set_name(const string& name);
	//void set_id(int id);
	//void print_student() const;



	Student() 
	{
		name = "";
		id = 0;
	}
	Student(int id, const string& name) {
		set_id(id);
		set_name(name);
	}
	string get_name() const 
	{ return name; }
	int get_id() const { return id; }
	void set_name(const string& name) { this->name = name; }
	void set_id(int id) { this->id = id; }
	void print_student() const {
		cout << id << " " << name << endl;;
	}




private:
	string name;
	int id;
};

#endif
