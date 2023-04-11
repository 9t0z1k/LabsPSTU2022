#include <iostream>
#include "person.h"
#include "Student.h"

void f1(Person& p)
{
    p.set_name("John");
    p.set_age(14);
    std::cout << p;
}

Student f2()
{
    Student l("Travis", 13, "Physics", 2);
    return l;
}

int main()
{
    Person a;
    std::cin >> a;
    std::cout << a;
    Person b("Ivan", 10);
    std::cout << b;
    a = b;
    std::cout << a;
   
    Student c;
    std::cin >> c;
    std::cout << c;
   
    f1(c);
    c = f2();
    std::cout << c;
    
    return 0;
}