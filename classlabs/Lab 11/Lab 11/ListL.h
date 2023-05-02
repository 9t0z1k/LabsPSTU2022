#pragma once
#include<iostream>
#include <list>
#include<algorithm>

using namespace std;
template <typename T>
class ListL {
private:
    list<T> data;

public:
    ListL() {}
    ~ListL(){}
    void average() {
        T sum = 0;
        for (const auto& element : data) {
            sum += element;
        }
        T avg = sum / data.size();
        data.push_back(avg);
    }
    void Delete(int s_range, int e_range)
    {
        auto s_it = data.begin();
        advance(s_it, s_range);
        auto e_it = data.begin();
        advance(e_it, e_range);
        data.erase(s_it, e_it);

    }
    void add_sum() {
        T min_value = *min_element(data.begin(), data.end());
        T max_value = *max_element(data.begin(), data.end());
        
        for (auto& element : data) {
            element += (min_value + max_value);
        }
    }
    void print_list() {
        cout << "List elements: ";
        for (const auto& element : data) {
            cout << element << " | ";
        }
        cout << std::endl;
    }
    void fill_list(int num_elements, bool is_integer = true) {
        data.clear();
        for (int i = 0; i < num_elements; ++i) {
            double random_num = is_integer ? rand() % 101 : rand() / (RAND_MAX + 1.0) * 100; 
            data.push_back(random_num);
        }
    }

};