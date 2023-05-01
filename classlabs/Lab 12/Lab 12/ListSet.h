#pragma once
#include <set>

template <typename T>
class ListSet {
public:

    void push(const T& value) {
        mData.insert(value);
    }

    void pop() {
        auto last_it = std::prev(mData.end());
        mData.erase(last_it);
    }

    T& operator[](std::size_t index) {
        auto it = mData.begin();
        std::advance(it, index);
        return *it;
    }

    const T& operator[](std::size_t index) const {
        auto it = mData.begin();
        std::advance(it, index);
        return *it;
    }

    std::size_t size() const {
        return mData.size();
    }

    bool empty() const {
        return mData.empty();
    }

    void clear() {
        mData.clear();
    }

    void print() const {
        for (const auto& item : mData) {
            std::cout << item << " | ";
        }
        std::cout << std::endl;
    }

    T average() const {
        T sum = 0;
        for (const auto& item : mData) {
            sum += item;
        }
        return sum / mData.size();
    }
    void remove_range(const T& key_start, const T& key_end, const T& key) {
        auto s_it = mData.lower_bound(key_start);
        auto e_it = mData.upper_bound(key_end);

        for (auto it = s_it; it != e_it; ) {
            if (*it == key) {
                it = mData.erase(it++);
            }
            else {
                ++it;
            }
        }
    }

    void add_min_max() {
        T min_val = *mData.begin();
        T max_val = *mData.rbegin();

        std::multiset<double> buffer;
        for (auto& x : mData) {
            buffer.insert(x + min_val + max_val);
        }
        mData.clear();
        mData.insert(buffer.begin(), buffer.end());
    }

private:
    std::multiset<T> mData;
};