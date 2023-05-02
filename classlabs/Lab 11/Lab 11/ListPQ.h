#pragma once
#include <iostream>
#include <queue>

using namespace std;

template<typename T>
class ListPQ {
private:
    priority_queue<T> data;
    priority_queue<T> buff;

public:
    ListPQ() {}
    ~ListPQ() {}
    
    void fill_LPQ() {
        int n;
        cout << "Enter size: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            T element;
            cout << "Enter elem: ";
            cin >> element;
            data.push(element);
        }
    }

    void average()
    {
        T sum = 0;
        while (!data.empty())
        {
            cout << data.top() << " | ";
            sum = sum + data.top();
            buff.push(data.top());
            data.pop();
        }
        sum /= buff.size();
        buff.push(sum);
        cout << endl;
        cout << "Find avg and push back to container: \n";
        while (!buff.empty())
        {
            cout << buff.top() << " | ";
            data.push(buff.top());
            buff.pop();
        }
        cout << endl;
    }
    void Delete(int s_range, int e_range)
    {
        int ch = 1;
        while (!data.empty())
        {
            if ((ch < s_range || ch > e_range) )
                buff.push(data.top());
            data.pop();
            ch++;
        }
        while (!buff.empty())
        {
            cout << buff.top() << " | ";
            data.push(buff.top());
            buff.pop();
        }
        cout << endl;
    }
    void add_sum()
    {
        cout << "Adding sum to elems: \n";
        T max = data.top();
        T min = data.top();
        while (!data.empty())
        {
            if (data.top() > max) max = data.top();
            if (data.top() < min) min = data.top();
            buff.push(data.top());
            data.pop();
        }
        while (!buff.empty())
        {
            data.push(max + min + buff.top());
            buff.pop();
        }
        while (!data.empty())
        {
            buff.push(data.top());
            cout << data.top() << " | ";
            data.pop();
        }
        cout << endl;
    }
};