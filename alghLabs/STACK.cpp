#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* top = NULL; //  вверхний элемент списка

// Добавление элемента
void push(string key) {
    Node* temp = new Node;
    temp->data = key;
    temp->next = top;
    top = temp;
}
//Удаление элемента
void pop(string data) {
    Node* temp = top;
    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Key not found" << endl;
        return;
    }
    if (prev == NULL) {
        top = top->next;
    }
    else {
        prev->next = temp->next;
    }
    delete temp;
}
// Вывод стека
void printStack() {
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//Добавление К элементов в конец
void addK(int k) {
    Node* temp = top;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    for (int i = 0; i < k; i++) {
        string data;
        cin >> data;
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
}

int main() {
    push("One");
    push("Two");
    push("Three");
    printStack();
    pop("Two");
    printStack();
    addK(2);
    printStack();

    return 0;
}