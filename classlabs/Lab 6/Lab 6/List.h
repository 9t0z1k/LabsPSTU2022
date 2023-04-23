#pragma once
#include <cstddef>
#include <iostream>

struct Node {
    int key;
    Node* next = NULL;
    Node* prev = NULL;
    Node();
    Node(int k, Node* n, Node* p);
};


class Iterator {
    friend class List;
private:
    Node* current = NULL;
public:
    Iterator() { current = NULL; }
    Iterator(Node* node) : current(node) {}
    bool operator==(const Iterator& other) const { //���������� ������� ����
        return current == other.current;           // � ���� ������� ��������� 
    }                                              //
    bool operator!=(const Iterator& other) const { // �� ��������� � �����������.
        return current != other.current;
    }
    int& operator*() const { // �������� ������������� ���������
        return current->key;
    }
    Iterator& operator++() { //++i
        current = current->next;
        return *this;
    }
    Iterator operator++(int) { // i++
        Iterator old = *this;
        current = current->next;
        return old;
    }
    Iterator operator+(int n) const { // ������� ������ � n ��������
        Iterator it(*this);
        while (n > 0 && it.current != NULL) {
            it.current = it.current->next;
            n--;
        }
        return it;
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
    int& get(int index);

    int& operator[](int index) {
        return get(index); // ���������� ������ �� ������� �� �������
    }
    // ����� ���������� �������� � ����� ������
    void push_back(int k);
    void pop(int key);

    int list_size() {
        return size;
    }

    void clear();
    void print() const;

    friend std::ostream& operator<<(std::ostream& out, const List& list);
    friend std::istream& operator>>(std::istream& in, List& list);

    Iterator beg() {
        return Iterator(head); // ���������� �������� �� ������ �������
    }
    Iterator end() {
        return Iterator(tail); // ���������� �������� �� ��������� �������
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