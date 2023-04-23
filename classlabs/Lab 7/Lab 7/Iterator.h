#pragma once
#include "List.h"

template <class T>
class Iterator
{
    friend class List;
private:
    List *list;
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
        return list != other.list || in != other.in; // ���������� ��������� � �������
    }

    // �������� ++
    Iterator& operator++() {
        in++; // ����������� ������
        return *this; // ���������� ����
    }
    friend Iterator operator+(const Iterator& it, int n) {
        return Iterator(it.list, it.in + n); // ���������� ����� �������� � ����������� ��������
    }
};