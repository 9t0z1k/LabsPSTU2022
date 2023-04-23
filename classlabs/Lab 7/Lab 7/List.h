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
        Node<T>* current = head; // начинаем с головы списка
        int i = 0;
        while (i < index && current->next != NULL) {
            current = current->next; // переходим к следующему узлу
        }
        return current->key; // возвращаем ссылку на данные узла
    }

    T& operator[](int index) {
        return get(index); // возвращаем ссылку на элемент по индексу
    }
    // Метод добавления элемента в конец списка
    void push_back(T k) {
        Node<T>* node = new Node<T>(k); // Создаем новый узел
        if (tail == NULL) { // Если список пустой
            head = node;
            tail = node;
        }
        else { // Если список не пустой
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    // Метод добавления элемента в начало списка
    void push_front(T k) {
        Node<T>* node = new Node<T>(k); // Создаем новый узел
        if (head == NULL) { // Если список пустой
            head = node;
            tail = node;
        }
        else { // Если список не пустой
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }

    void pop(T key) {
        Node<T>* p = head;
        while (p != NULL && p->key != key) { // Проходим по списку до нужного ключа
            p = p->next;
        }
        if (p != NULL) { // Если нашли узел по позиции
            if (p->prev != NULL) { // Если узел не является головным
                p->prev->next = p->next;
            }
            else { // Если узел является головным
                head = p->next;
            }
            if (p->next != NULL) { // Если узел не является хвостовым
                p->next->prev = p->prev;
            }
            else { // Если узел является хвостовым
                tail = p->prev;
            }
            delete p; // Удаляем текущий узел из памяти
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
            delete q; // Удаляем текущий узел из памяти
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
            return list != other.list || in != other.in; // сравниваем указатели и индексы
        }

        // оператор ++
        Iterator& operator++() {
            in++; // увеличиваем индекс
            return *this; // возвращаем себя
        }
        friend Iterator operator+(const Iterator& it, int n) {
            return Iterator(it.list, it.in + n); // возвращаем новый итератор с увеличенным индексом
        }
    };
    Iterator beg() {
        return Iterator(this, 0); // возвращаем итератор на первый элемент
    }
    Iterator end() {
        return Iterator(this, size); // возвращаем итератор за последний элемент
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
