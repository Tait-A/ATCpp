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

    MyVector(const T* arr, std::size_t arr_size)
    : data(nullptr)
    , size(size)
    , growth_factor(2)
    , capacity(10) {
        while (arr_size > capacity) {
            capacity *= growth_factor;
        }
        data = new T[capacity];
        for (std::size_t i = 0; i < arr_size; ++i) {
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

    MyVector operator=(const MyVector& vec){
        if (this == &vec) {
            return *this;
        }
        delete[] data;
        size = vec.size;
        capacity = vec.capacity;
        growth_factor = vec.growth_factor;

        data = new T[capacity];
        std::copy(vec.data, vec.data + size, data);
        return *this;
    }

    MyVector operator=(MyVector&& vec){
        if (this == &vec) {
            return *this;
        }
        delete[] data;
        size = vec.size;
        capacity = vec.capacity;
        growth_factor = vec.growth_factor;

        data = vec.data;
        vec.data = nullptr;
        vec.size = 0;
        return *this;
    }

    ~MyVector() {
        delete[] data;
    }

    T& operator[](const int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](const int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    bool operator==(const MyVector& vec) const {
        if (this == &vec) {
            return true;
        } else if (size != vec.size) {
            return false;
        } else {
            for (int i; i < size; i++) {
                if (data[i] != vec.data[i]) {
                    return false;
                }
            }
            return true;
        }
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

    T pop() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[--size];
    }

    void reserve(std::size_t new_cap) {
        if (new_cap == 0) {
            throw std::invalid_argument("New capacity must be greater than 0");
        }
        if (new_cap < size) {
            throw std::invalid_argument("New capacity must not be less than size");
        }
        if (new_cap == capacity) {
            return;
        }
        T* new_data = new T[new_cap];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return data + size;
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }
};

int vectoring();

#endif // MY_VECTOR_H