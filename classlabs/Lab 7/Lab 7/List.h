#pragma once
#include <cstddef>
#include <iostream>

template <class T>
struct Node {
    T key;
    Node<T>* next;
    Node<T>* prev;

    Node(T k, Node<T>* n = NULL, Node<T>* p = NULL) {
        key = k;
        next = n;
        prev = p;
    }
};

template <class T>

class List {
    Node<T>* head;
    Node<T>* tail;
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
    T& get(int index) {
        Node<T>* current = head; // �������� � ������ ������
        int i = 0;
        while (i < index && current->next != NULL) {
            current = current->next; // ��������� � ���������� ����
        }
        return current->key; // ���������� ������ �� ������ ����
    }

    T& operator[](int index) {
        return get(index); // ���������� ������ �� ������� �� �������
    }
    // ����� ���������� �������� � ����� ������
    void push_back(T k) {
        Node<T>* node = new Node<T>(k); // ������� ����� ����
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
    void push_front(T k) {
        Node<T>* node = new Node<T>(k); // ������� ����� ����
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

    void pop(T key) {
        Node<T>* p = head;
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
        Node<T>* p = head;
        while (p != NULL) {
            Node<T>* q = p;
            p = p->next;
            delete q; // ������� ������� ���� �� ������
        }
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void print() {
        Node<T>* node = head;
        while (node != NULL) {
            std::cout << node->key << "->";
            node = node->next;
        }
        std::cout << std::endl;
    }
    class Iterator
    {
    private:
        List<T>* list;
        int in;
    public:
        Iterator() { in = 0; }
        Iterator(List<T>* list, int index) {
            this->list = list;
            this->in = index;
        }
        T& operator*() {
                return list->get(in);
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
    Iterator beg() {
        return Iterator(this, 0); // ���������� �������� �� ������ �������
    }
    Iterator end() {
        return Iterator(this, size); // ���������� �������� �� ��������� �������
    }

    friend List<T> operator*(List<T>& left, List<T>& right) {
        List<T> result;
        Iterator it1 = left.beg();
        Iterator it2 = right.beg();
        while (it1 != left.end() && it2 != right.end()) {
            T res = (*it1) * (*it2);
            result.push_back(res);
            ++it1;
            ++it2;
        }
        return result;
    }

};
