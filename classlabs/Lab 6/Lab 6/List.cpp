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
    Node* current = head; // �������� � ������ ������
    int i = 0;
    while (i < index && current->next != NULL) {
        current = current->next; // ��������� � ���������� ����
    }
    return current->key; // ���������� ������ �� ������ ����
}

void List::push_back(int k)
{
    Node* newNode = new Node(k, NULL, tail); // ������� ����� ���� � ������ key, ���������� �� ��������� ���� ������ NULL � ���������� �� ���������� ���� ������ tail
    if (tail != NULL) {
        tail->next = newNode; // ���� tail �� ����� NULL, �� ������������� ��������� �� ��������� ���� � tail �� ����� ����
    }
    tail = newNode; // ������������� tail �� ����� ����
    if (head == NULL) {
        head = newNode; // ���� ������ ��� ������, �� ������������� head �� ����� ����
    }
    size++;
}

void List::pop(int key) {
    Node* p = head;
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

void List::clear()
{
    Node* p = head;
    while (p != NULL) {
        Node* q = p;
        p = p->next;
        delete q; // ������� ������� ���� �� ������
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
