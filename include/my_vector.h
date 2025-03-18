#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>
#include <algorithm>

template <typename T>
class MyVector {
private:
    T* data;
    std::size_t size;
    int growth_factor;
    std::size_t capacity;

public:
    MyVector()
    : data(nullptr)
    , size(0)
    , growth_factor(2)
    , capacity(10){
        data = new T[capacity];
    }

    MyVector(const T* arr, std::size_t size)
    : data(nullptr)
    , size(size)
    , growth_factor(2)
    , capacity(10) {
        while (sizeof(arr) > capacity) {
            capacity *= growth_factor;
        }
        data = new T[capacity];
        for (std::size_t i = 0; i < sizeof(arr); ++i) {
            data[i] = arr[i];
            size++;
        }
    }

    MyVector(const MyVector& vec)
    : data(nullptr)
    , size(vec.size)
    , growth_factor(2)
    , capacity(vec.capacity) {
        data = new T[capacity];
        std::copy(vec.data, vec.data + size, data);
    }

    MyVector(MyVector&& vec)
    : data(vec.data)
    , size(vec.size)
    , growth_factor(2)
    , capacity(vec.capacity) {
        vec.data = nullptr;
        vec.size = 0;
    }

    ~MyVector() {
        delete[] data;
    }

    T& operator[](const int index) {
        return data[index];
    }

    std::size_t get_size() const {
        return size;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            T* new_data = new T[capacity * growth_factor];
            for (std::size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity *= growth_factor;
        }
        data[size++] = value;
    }
};

#endif // MY_VECTOR_H