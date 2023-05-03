#pragma once
#include <iostream>

class Stack {
public:
    Stack(int size) {
        data = new int[size];
        this->size = size;
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (topIndex < size - 1) {
            data[++topIndex] = value;
        }
        else {
            throw "Stack overflow\n";
        }
    }
    int pop() {
        if (!isEmpty()) return data[topIndex--];
  
        else throw "Stack underflow";
    }

    int peek() {
        if (!isEmpty()) return data[topIndex];
            
        else {
            throw "Stack is empty";
        }
    }

    bool isEmpty() { return topIndex == -1; }

    bool isFull() { return topIndex + 1 == size; }

    class Iterator {
    public:
        Iterator(Stack* stack, int index) {
            this->stack = stack;
            currentIndex = index;
        }

        int operator*() {
            return stack->data[currentIndex];
        }

        Iterator& operator++() {
            --currentIndex;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return currentIndex != other.currentIndex;
        }

        Iterator operator+(int n) const {
            Iterator result = *this;
            result.currentIndex += n;
            return result;
        }

    private:
        Stack* stack;
        int currentIndex;
    };
    
    Iterator begin() {
        return Iterator(this, topIndex);
    }

    Iterator end() {
        return Iterator(this, -1);
    }
protected:
    int* data;
    int size;
    int topIndex;
};

