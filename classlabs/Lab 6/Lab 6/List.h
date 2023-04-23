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
    bool operator==(const Iterator& other) const { //сравнивают текущий узел
        return current == other.current;           // и узел другого итератора 
    }                                              //
    bool operator!=(const Iterator& other) const { // на равенство и неравенство.
        return current != other.current;
    }
    int& operator*() const { // операция разыменования итератора
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
    Iterator operator+(int n) const { // переход вправо к n элементу
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
        return get(index); // возвращаем ссылку на элемент по индексу
    }
    // Метод добавления элемента в конец списка
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
        return Iterator(head); // возвращаем итератор на первый элемент
    }
    Iterator end() {
        return Iterator(tail); // возвращаем итератор на последний элемент
    }
    friend List operator*(List& left, List& right) {
        List result; // создаем новый список
        Iterator it1 = left.beg(); // итератор по первому списку
        Iterator it2 = right.beg(); // итератор по второму списку
        while (it1 != left.end() && it2 != right.end()) {
            result.push_back(*it1 * *it2); // добавляем произведение элементов в новый список
            ++it1; // переходим к следующему элементу первого списка
            ++it2; // переходим к следующему элементу второго списка
        }
        return result; // возвращаем новый список
    }

};