#pragma once
#include <cstddef>
#include <iostream>
#include <fstream>

template <typename T>
struct Node {
    T key;
    Node<T>* next = NULL;
    Node<T>* prev = NULL;
    Node();
    Node(T k, Node<T>* n, Node<T>* p);
};

template<typename T>
class Iterator {
    template<typename T>
    friend class List;
private:
    Node<T>* current = NULL;
public:
    Iterator() { current = NULL; }
    Iterator(Node<T>* node) : current(node) {}
    bool operator==(const Iterator<T>& other) const { //���������� ������� ����
        return current == other.current;           // � ���� ������� ��������� 
    }                                              //
    bool operator!=(const Iterator<T>& other) const { // �� ��������� � �����������.
        return current != other.current;
    }
    bool operator<(const Iterator<T>& other) const {
        return current < other.current;
    }
    bool operator>(const Iterator<T>& other) const {
        return current > other.current;
    }
    bool operator<=(const Iterator<T>& other) const {
        return current <= other.current;
    }
    bool operator>=(const Iterator<T>& other) const {
        return current >= other.current;
    }
    T& operator*() const { // �������� ������������� ���������
        return current->key;
    }
    friend Iterator operator+(const Iterator<T>& lit, const Iterator<T>& rit) {
        Iterator<T> result(lit); // ������� ����� ������ ���������
        while (result.current != rit.current) { // ���� �� ������ �� ������� ���������
            ++result; // ��������� � ���������� �������� ������
        }
        return result; // ���������� ����� ��������
    }
    Iterator& operator++() { //++i
        current = current->next;
        return *this;
    }
    Iterator operator++(int) { // i++
        Iterator<T> old = *this;
        current = current->next;
        return old;
    }
    Iterator operator+(int n) const { // ������� ������ � n ��������
        Iterator<T> it(*this);
        while (n > 0 && it.current != NULL) {
            it.current = it.current->next;
            n--;
        }
        return it;
    }
    Iterator& operator=(const Iterator& other) {
        if (this != &other) { // ���� ���������� �������� �� ����� ��������
            current = other.current;
        }
        return *this;
    }
    Iterator& operator=(const T& value) {
        current->key = value;
        return *this;
    }
};

template<typename T>
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
    List(size_t size, const T& v)
    {
        for (size_t i = 0; i < size; ++i)
            push_back(v);
    }
    ~List() {
        clear();
    }
    T& get(int index);

    T& operator[](int index) {
        return get(index); // ���������� ������ �� ������� �� �������
    }
    // ����� ���������� �������� � ����� ������
    void push_back(T k);
    void insert(int pos, const T& value);
    void pop(T key);

    int list_size() {
        return size;
    }

    void clear();
    void print() const;

    friend std::ostream& operator<<(std::ostream& out, const List<T>& list)
    {
        list.print();
        return out;
    }
    friend std::istream& operator>>(std::istream& in, List<T>& list)
    {
        int k;
        in >> k;
        list.push_back(k);
        return in;
    }
    Iterator<T> begin() {
        return Iterator<T>(head); // ���������� �������� �� ������ �������
    }
    Iterator<T> end() {
        return Iterator<T>(tail->next); // ���������� �������� �� ��������� �������
    }

    friend List<T> operator*(List<T>& left, List<T>& right) {
        List<T> result; // ������� ����� ������
        Iterator<T> it1 = left.beg(); // �������� �� ������� ������
        Iterator<T> it2 = right.beg(); // �������� �� ������� ������
        while (it1 != left.end() && it2 != right.end()) {
            T res = (*it1) * (*it2);
            result.push_back(res); // ��������� ������������ ��������� � ����� ������
            ++it1; // ��������� � ���������� �������� ������� ������
            ++it2; // ��������� � ���������� �������� ������� ������
        }
        return result; // ���������� ����� ������
    }

};

template<typename T>
Node<T>::Node(T k, Node<T>* n, Node<T>* p)
{
    key = k;
    next = n;
    prev = p;
}

template<typename T>
T& List<T>::get(int index)
{
    Node<T>* current = head; // �������� � ������ ������
    int i = 0;
    while (i < index && current->next != NULL) {
        current = current->next; // ��������� � ���������� ����
    }
    return current->key; // ���������� ������ �� ������ ����
}

template<typename T>
void List<T>::push_back(T k)
{
    Node<T>* newNode = new Node<T>(k, NULL, tail); // ������� ����� ���� � ������ key, ���������� �� ��������� ���� ������ NULL � ���������� �� ���������� ���� ������ tail
    if (tail != NULL) {
        tail->next = newNode; // ���� tail �� ����� NULL, �� ������������� ��������� �� ��������� ���� � tail �� ����� ����
    }
    tail = newNode; // ������������� tail �� ����� ����
    if (head == NULL) {
        head = newNode; // ���� ������ ��� ������, �� ������������� head �� ����� ����
    }
    size++;
}

template<typename T>
void List<T>::pop(T key) {
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

template<typename T>
void List<T>::clear()
{
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

template<typename T>
void List<T>::print() const
{
    Node<T>* node = head;
    while (node != NULL) {
        std::cout << node->key << "->";
        node = node->next;
    }
    std::cout << std::endl;
}

template<typename T>
void List<T>::insert(int pos, const T& value)
{
    if (pos < 0 || pos > size) {
        throw std::out_of_range("Invalid position");
    }
    if (pos == size) {
        push_back(value);
        return;
    }
    Node<T>* newNode = new Node<T>(value, NULL, tail);
    Node<T>* currentNode = head;
    for (int i = 0; i < pos; ++i) {
        currentNode = currentNode->next;
    }
    newNode->next = currentNode;
    newNode->prev = currentNode->prev;
    if (newNode->prev != nullptr) {
        newNode->prev->next = newNode;
    }
    else {
        head = newNode;
    }
    currentNode->prev = newNode;
    ++size;
}
