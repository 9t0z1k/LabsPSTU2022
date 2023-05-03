#include <iostream>
#include "Stack.h"

int main() {
    // создание стека на 5 элементов
    Stack myStack(5);

    // проверка функций push и peek
    std::cout << "Pushing 5 elements onto the stack: ";
    for (int i = 0; i < 5; i++) {
        myStack.push(i);
        std::cout << myStack.peek() << " ";
    }
    std::cout << std::endl;

    // проверка функций pop и isEmpty
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

    // проверка итератора
    std::cout << "Using an iterator to print the elements: ";
    for (auto it = myStack.begin(); it != myStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
} 