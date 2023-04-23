#include "List.h"
#include <cstddef>

template <class T>
Node<T>::Node(T k, Node<T>* n, Node<T>* p) {
    key = k;
    next = n;
    prev = p;
}

template <class T>
List<T>::List() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
int& List<T>::get(int index) {
    Node<T>* current = head; // �������� � ������ ������
    int i = 0;
    while (i < index && current->next != NULL) {
        current = current->next; // ��������� � ���������� ����
    }
    return current->key; // ���������� ������ �� ������ ����
}

template <class T>
int& List<T>::operator [](int index) {
    return get(index); // ���������� ������ �� ������� �� �������
}

template <class T>
void List<T>::push_back(T k) {
    Node<T>* node = new Node(k); // ������� ����� ����
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

template <class T>
void List<T>::push_front(T k) {
    Node<T>* node = new Node(k); // ������� ����� ����
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

template <class T>
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

template <class T>
void List<T>::clear() {
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

template <class T>
void List<T>::print() {
    Node<T>* node = head;
    while (node != NULL) {
        std::cout << node->key << "->";
        node = node->next;
    }
    std::cout << std::endl;
}
