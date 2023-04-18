#pragma once
#include <cstddef>
#include <iostream>

struct Node {
    int key;
    Node* next;
    Node* prev;

    Node(int k, Node* n = NULL, Node* p = NULL) {
        key = k;
        next = n;
        prev = p;
    }
};

class List {
    Node* head;
    Node* tail;
    int size;

public:
    List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    ~List() {
        clear();
    }
    int& get(int index) {
        Node* current = head; // �������� � ������ ������
        int i = 0;
       while(i < index && current->next != NULL) {
            current = current->next; // ��������� � ���������� ����
       }
        return current->key; // ���������� ������ �� ������ ����
    }
    
    int& operator[](int index) {
        return get(index); // ���������� ������ �� ������� �� �������
    }
    // ����� ���������� �������� � ����� ������
    void push_back(int k) {
        Node* node = new Node(k); // ������� ����� ����
        if (tail == NULL) { // ���� ������ ������
            head = node; 
            tail = node;
        }
        else { // ���� ������ �� ������
            node->prev = tail; 
            tail->next = node; 
            tail = node; 
        }
        size++;
    }

    // ����� ���������� �������� � ������ ������
    void push_front(int k) {
        Node* node = new Node(k); // ������� ����� ����
        if (head == NULL) { // ���� ������ ������
            head = node; 
            tail = node;
        }
        else { // ���� ������ �� ������
            node->next = head;
            head->prev = node; 
            head = node;
        }
        size++;
    }

    void pop(int key) {
        Node* p = head; 
        while (p != NULL && p->key != key) { // �������� �� ������ �� ������� �����
            p = p->next;
        }
        if (p != NULL) { // ���� ����� ���� �� �������
            if (p->prev != NULL) { // ���� ���� �� �������� ��������
                p->prev->next = p->next; 
            }
            else { // ���� ���� �������� ��������
                head = p->next; 
            }
            if (p->next != NULL) { // ���� ���� �� �������� ���������
                p->next->prev = p->prev; 
            }
            else { // ���� ���� �������� ���������
                tail = p->prev; 
            }
            delete p; // ������� ������� ���� �� ������
            size--; 
        }
    }

    int list_size() {
        return size;
    }

    void clear() {
        Node* p = head; 
        while (p != NULL) {  
            Node* q = p; 
            p = p->next; 
            delete q; // ������� ������� ���� �� ������
        }
        head = NULL; 
        tail = NULL;
        size = 0; 
    }

    void print() {
        Node* node = head; 
        while (node != NULL) { 
            std::cout << node->key << "->"; 
            node = node->next; 
        }
        std::cout << std::endl; 
    }
  class Iterator
    {
    private:
        List* list;
        int in;
    public:
        Iterator() {}
        Iterator(List* list, int index) {
            this->list = list;
            this->in = index;
        }
        int& operator*() {
            if (this == nullptr)
                return list->get(in);
            else
                return in;
        }
        bool operator!=(const Iterator& other) {
            return list != other.list || in != other.in; // ���������� ��������� � �������
        }

        // �������� ++
        Iterator& operator++() {
            in++; // ����������� ������
            return *this; // ���������� ����
        }
        friend Iterator operator+(const Iterator& it, int n) {
            return Iterator(it.list, it.in + n); // ���������� ����� �������� � ����������� ��������
        }
    };
    Iterator beg(){
        return Iterator(this, 0); // ���������� �������� �� ������ �������
    }
    Iterator end() {
        return Iterator(this, size); // ���������� �������� �� ��������� �������
    }
    friend List operator*(List& left, List& right) {
        List result; // ������� ����� ������
        Iterator it1 = left.beg(); // �������� �� ������� ������
        Iterator it2 = right.beg(); // �������� �� ������� ������
        while (it1 != left.end() && it2 != right.end()) {
            result.push_back(*it1 * *it2); // ��������� ������������ ��������� � ����� ������
            ++it1; // ��������� � ���������� �������� ������� ������
            ++it2; // ��������� � ���������� �������� ������� ������
        }
        return result; // ���������� ����� ������
    }

};