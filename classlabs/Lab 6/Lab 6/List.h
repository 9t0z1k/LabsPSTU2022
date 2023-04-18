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
        Node* current = head; // начинаем с головы списка
        int i = 0;
       while(i < index && current->next != NULL) {
            current = current->next; // переходим к следующему узлу
       }
        return current->key; // возвращаем ссылку на данные узла
    }
    
    int& operator[](int index) {
        return get(index); // возвращаем ссылку на элемент по индексу
    }
    // ћетод добавлени€ элемента в конец списка
    void push_back(int k) {
        Node* node = new Node(k); // —оздаем новый узел
        if (tail == NULL) { // ≈сли список пустой
            head = node; 
            tail = node;
        }
        else { // ≈сли список не пустой
            node->prev = tail; 
            tail->next = node; 
            tail = node; 
        }
        size++;
    }

    // ћетод добавлени€ элемента в начало списка
    void push_front(int k) {
        Node* node = new Node(k); // —оздаем новый узел
        if (head == NULL) { // ≈сли список пустой
            head = node; 
            tail = node;
        }
        else { // ≈сли список не пустой
            node->next = head;
            head->prev = node; 
            head = node;
        }
        size++;
    }

    void pop(int key) {
        Node* p = head; 
        while (p != NULL && p->key != key) { // ѕроходим по списку до нужного ключа
            p = p->next;
        }
        if (p != NULL) { // ≈сли нашли узел по позиции
            if (p->prev != NULL) { // ≈сли узел не €вл€етс€ головным
                p->prev->next = p->next; 
            }
            else { // ≈сли узел €вл€етс€ головным
                head = p->next; 
            }
            if (p->next != NULL) { // ≈сли узел не €вл€етс€ хвостовым
                p->next->prev = p->prev; 
            }
            else { // ≈сли узел €вл€етс€ хвостовым
                tail = p->prev; 
            }
            delete p; // ”дал€ем текущий узел из пам€ти
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
            delete q; // ”дал€ем текущий узел из пам€ти
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
            return list != other.list || in != other.in; // сравниваем указатели и индексы
        }

        // оператор ++
        Iterator& operator++() {
            in++; // увеличиваем индекс
            return *this; // возвращаем себ€
        }
        friend Iterator operator+(const Iterator& it, int n) {
            return Iterator(it.list, it.in + n); // возвращаем новый итератор с увеличенным индексом
        }
    };
    Iterator beg(){
        return Iterator(this, 0); // возвращаем итератор на первый элемент
    }
    Iterator end() {
        return Iterator(this, size); // возвращаем итератор за последний элемент
    }
    friend List operator*(List& left, List& right) {
        List result; // создаем новый список
        Iterator it1 = left.beg(); // итератор по первому списку
        Iterator it2 = right.beg(); // итератор по второму списку
        while (it1 != left.end() && it2 != right.end()) {
            result.push_back(*it1 * *it2); // добавл€ем произведение элементов в новый список
            ++it1; // переходим к следующему элементу первого списка
            ++it2; // переходим к следующему элементу второго списка
        }
        return result; // возвращаем новый список
    }

};