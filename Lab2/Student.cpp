#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<iostream>

using namespace std;

class Student

{

public:

	Student()
	{

		this->name = "";
		this->id = 0;

	}

	Student(int id, const string& name)
	{

		this->id = id;

		this->name = name;

	}

	string get_name() const

	{

		return this->name;

	}

	int get_id() const

	{

		return this->id;

	}

	void set_name(const string& name)
	{

		this->name = name;

	}

	void set_id(int id)
	{

		this->id = id;

	}

	void print_student() const
	{

		cout << this->id << " " << this->name << endl;

	}

private:

	//Student name
	string name;

	// Student ID
	int id;

};

struct NodeType

{

	Student student;

	NodeType* next;

	NodeType() : student(), next(nullptr)

	{}

	NodeType(const Student& s) : student(s), next(nullptr)

	{}

};

#endif

