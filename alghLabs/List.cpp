#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* prev;
    Node* next;
};

void remove(Node*& head, const std::string& key) {
    for (Node* p = head; p != nullptr; p = p->next) {
        if (p->data == key) {
            if (p->prev != nullptr) {
                p->prev->next = p->next;
            }
            else {
                head = p->next;
            }
            if (p->next != nullptr) {
                p->next->prev = p->prev;
            }
            delete p;
            return;
        }
    }
}

void add(Node*& head, int k, const std::string& data) {
    Node* tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }

    for (int i = 0; i < k; ++i) {
        Node* newNode = new Node{ data, tail, nullptr };
        if (tail != nullptr) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
    }
}

int main() {
    Node* head = nullptr;

    add(head, 1, "one");
    add(head, 1, "two");
    add(head, 1, "three");
    add(head, 1, "four");

    for (Node* p = head; p != nullptr; p = p->next) {
        std::cout << p->data << ' ';
    }
    std::cout << '\n';

    remove(head, "three");

    for (Node* p = head; p != nullptr; p = p->next) {
        std::cout << p->data << ' ';
    }
    std::cout << '\n';

    add(head, 2, "five");

    for (Node* p = head; p != nullptr; p = p->next) {
        std::cout << p->data << ' ';
    }
    std::cout << '\n';

    // Удаление узлов Списка
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}