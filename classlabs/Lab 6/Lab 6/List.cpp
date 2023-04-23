#include "List.h"

#include "List.h"

Node::Node(int k, Node* n, Node* p)
{
    key = k;
    next = n;
    prev = p;
}

int& List::get(int index)
{
    Node* current = head; // начинаем с головы списка
    int i = 0;
    while (i < index && current->next != NULL) {
        current = current->next; // переходим к следующему узлу
    }
    return current->key; // возвращаем ссылку на данные узла
}

void List::push_back(int k)
{
    Node* newNode = new Node(k, NULL, tail); // создаем новый узел с ключом key, указателем на следующий узел равным NULL и указателем на предыдущий узел равным tail
    if (tail != NULL) {
        tail->next = newNode; // если tail не равен NULL, то устанавливаем указатель на следующий узел у tail на новый узел
    }
    tail = newNode; // устанавливаем tail на новый узел
    if (head == NULL) {
        head = newNode; // если список был пустой, то устанавливаем head на новый узел
    }
    size++;
}

void List::pop(int key) {
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

void List::clear()
{
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

void List::print() const
{
    Node* node = head;
    while (node != NULL) {
        std::cout << node->key << "->";
        node = node->next;
    }
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& out, const List& list)
{
    list.print();
    return out;
}

std::istream& operator>> (std::istream& in, List& list)
{
    int k;
    in >> k;
    list.push_back(k);
    return in;
}
