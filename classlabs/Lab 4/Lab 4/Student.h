#pragma once
#include "person.h"
#include <iostream>
#include <string>

class Student :
    public Person
{
protected:
    std::string subject;
    int grade;
public:
    Student(void);
    Student(std::string, int, std::string, int);
    Student(const Student&);
    ~Student() {};
    std::string get_subject() { return subject; }
    int get_grade() { return grade; }
    void set_subject(std::string);
    void set_grade(int);
    Student& operator=(const Student&);
    void succsess(int);
    friend std::istream& operator>>(std::istream& in, Student& s);
    friend std::ostream& operator<<(std::ostream& out, Student& s);
};

