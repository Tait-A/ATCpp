#include "my_vector.h"
#include <iostream>


int vectoring() {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    std::cout << sizeof(vec) << std::endl;
    MyVector<int> vec2 = vec;
    MyVector<int> vec3 = std::move(vec);

    int value = vec2[0];
    return 0;
}

