#include <iostream>
#include <string>

struct Node {
    std::string key;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void enqueue(std::string key) {
    Node* newNode = new Node{ key, nullptr };
    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void dequeue(std::string key) {
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            if (current == tail) {
                tail = prev;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    enqueue("one");
    enqueue("two");
    enqueue("three");
    print();

    dequeue("two");
    print();

    enqueue("four");
    enqueue("five");
    print();

    return 0;
}