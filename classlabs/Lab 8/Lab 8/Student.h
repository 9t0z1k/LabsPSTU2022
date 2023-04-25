#pragma once
#include "Person.h"
#include "Object.h"
#include <iostream>
#include <string>

class Student :
    public Person
{
public:
    Student(void);
    Student(std::string, int, std::string, int);
    Student(const Student&);
    ~Student() {};
    void Show();
    void Input();
    std::string get_subject() { return subject; }
    int get_grade() { return grade; }
    void set_subject(std::string);
    void set_grade(int);
    Student& operator=(const Student&);
    int AvgAge() { return age; }
protected:
    std::string subject;
    int grade;
};

