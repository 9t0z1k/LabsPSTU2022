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
    Node<T>* current = head; // начинаем с головы списка
    int i = 0;
    while (i < index && current->next != NULL) {
        current = current->next; // переходим к следующему узлу
    }
    return current->key; // возвращаем ссылку на данные узла
}

template <class T>
int& List<T>::operator [](int index) {
    return get(index); // возвращаем ссылку на элемент по индексу
}

template <class T>
void List<T>::push_back(T k) {
    Node<T>* node = new Node(k); // Создаем новый узел
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

template <class T>
void List<T>::push_front(T k) {
    Node<T>* node = new Node(k); // Создаем новый узел
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

template <class T>
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

template <class T>
void List<T>::clear() {
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

template <class T>
void List<T>::print() {
    Node<T>* node = head;
    while (node != NULL) {
        std::cout << node->key << "->";
        node = node->next;
    }
    std::cout << std::endl;
}
