#pragma once
#include <cstddef>
#include <iostream>

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
    bool operator==(const Iterator<T>& other) const { //сравнивают текущий узел
        return current == other.current;           // и узел другого итератора 
    }                                              //
    bool operator!=(const Iterator<T>& other) const { // на равенство и неравенство.
        return current != other.current;
    }
    T& operator*() const { // операция разыменования итератора
        return current->key;
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
    Iterator operator+(int n) const { // переход вправо к n элементу
        Iterator<T> it(*this);
        while (n > 0 && it.current != NULL) {
            it.current = it.current->next;
            n--;
        }
        return it;
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
    ~List() {
        clear();
    }
    T& get(int index);

    T& operator[](int index) {
        return get(index); // возвращаем ссылку на элемент по индексу
    }
    // Метод добавления элемента в конец списка
    void push_back(T k);
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

    Iterator<T> beg() {
        return Iterator<T>(head); // возвращаем итератор на первый элемент
    }
    Iterator<T> end() {
        return Iterator<T>(tail->next); // возвращаем итератор на последний элемент
    }

    friend List<T> operator*(List<T>& left, List<T>& right) {
        List<T> result; // создаем новый список
        Iterator<T> it1 = left.beg(); // итератор по первому списку
        Iterator<T> it2 = right.beg(); // итератор по второму списку
        while (it1 != left.end() && it2 != right.end()) {
            T res = (*it1) * (*it2);
            result.push_back(res); // добавляем произведение элементов в новый список
            ++it1; // переходим к следующему элементу первого списка
            ++it2; // переходим к следующему элементу второго списка
        }
        return result; // возвращаем новый список
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
    Node<T>* current = head; // начинаем с головы списка
    int i = 0;
    while (i < index && current->next != NULL) {
        current = current->next; // переходим к следующему узлу
    }
    return current->key; // возвращаем ссылку на данные узла
}

template<typename T>
void List<T>::push_back(T k)
{
    Node<T>* newNode = new Node<T>(k, NULL, tail); // создаем новый узел с ключом key, указателем на следующий узел равным NULL и указателем на предыдущий узел равным tail
    if (tail != NULL) {
        tail->next = newNode; // если tail не равен NULL, то устанавливаем указатель на следующий узел у tail на новый узел
    }
    tail = newNode; // устанавливаем tail на новый узел
    if (head == NULL) {
        head = newNode; // если список был пустой, то устанавливаем head на новый узел
    }
    size++;
}

template<typename T>
void List<T>::pop(T key) {
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

template<typename T>
void List<T>::clear()
{
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
