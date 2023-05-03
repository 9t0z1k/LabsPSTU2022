#include <iostream>
#include "Stack.h"

int main() {
    // �������� ����� �� 5 ���������
    Stack myStack(5);

    // �������� ������� push � peek
    std::cout << "Pushing 5 elements onto the stack: ";
    for (int i = 0; i < 5; i++) {
        myStack.push(i);
        std::cout << myStack.peek() << " ";
    }
    std::cout << std::endl;

    // �������� ������� pop � isEmpty
    std::cout << "Popping all elements off the stack: ";
    while (!myStack.isEmpty()) {
        std::cout << myStack.pop() << " ";
    }
    std::cout << std::endl;

    std::cout << "Pushing 5 elements onto the stack: ";
    for (int i = 0; i < 5; i++) {
        myStack.push(i);
        std::cout << myStack.peek() << " ";
    }
    std::cout << std::endl;

    // �������� ���������
    std::cout << "Using an iterator to print the elements: ";
    for (auto it = myStack.begin(); it != myStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
} 