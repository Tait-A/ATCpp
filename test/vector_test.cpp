#include <gtest/gtest.h>
#include "my_vector.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

template <typename T>
    int construct() {
        MyVector<T> vec1;
        MyVector<T> vec2(vec1);
        MyVector<T> vec3(std::move(vec1));
        MyVector<T> vec4 = vec2;
        MyVector<T> vec5 = std::move(vec2);
        return 0;
       }


TEST(VectorTest, Test_constructors)
{
    std::cout << construct<int>() << std::endl;
    EXPECT_FALSE(construct<int>());
    EXPECT_FALSE(construct<std::string>());
    EXPECT_FALSE(construct<float>());
    EXPECT_FALSE(construct<char>());
    EXPECT_FALSE(construct<std::vector<int>>());
    EXPECT_FALSE(construct<double>());
    EXPECT_FALSE(construct<long>());
    EXPECT_FALSE(construct<bool>());
}

template <typename T>
int push_back_test(T arr[]) {
    MyVector<T> vec;
    for (val : arr) {
        vec.push_back(val);
    }

    arr_size = sizeof(arr)
    if (vec.size() != )
}


TEST(VectorTest, Test_push_back) {
    MyVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    EXPECT_EQ(vec.get_size(), 4);

    int expected[] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(vec[i], expected[i]);
    }

    MyVector<float> vec_float;
    vec_float.push_back(1.1f);
    vec_float.push_back(2.2f);
    vec_float.push_back(3.3f);
    vec_float.push_back(4.4f);
    EXPECT_EQ(vec_float.get_size(), 4);
    float expected_float[] = {1.1f, 2.2f, 3.3f, 4.4f};
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(vec_float[i], expected_float[i]);
    }

    MyVector<std::string> vec_string;
    vec_string.push_back("Hello");
    vec_string.push_back("World");
    vec_string.push_back("!");

    EXPECT_EQ(vec_string.get_size(), 3);
    std::string expected_string[] = {"Hello", "World", "!"};
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(vec_string[i], expected_string[i]);
    }

    MyVector<std::vector<int>> vec_vector;
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    vec_vector.push_back(v1);
    vec_vector.push_back(v2);
    EXPECT_EQ(vec_vector.get_size(), 2);
    std::vector<int> expected_vector[] = {v1, v2};
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(vec_vector[i], expected_vector[i]);
    }

    MyVector<MyVector<int>> vec_vec;
    MyVector<int> inner_vec1;
    inner_vec1.push_back(1);
    inner_vec1.push_back(2);
    MyVector<int> inner_vec2;
    inner_vec2.push_back(3);
    inner_vec2.push_back(4);
    vec_vec.push_back(inner_vec1);
    vec_vec.push_back(inner_vec2);
    EXPECT_EQ(vec_vec.get_size(), 2);
    MyVector<int> expected_inner_vec1 = inner_vec1;
    MyVector<int> expected_inner_vec2 = inner_vec2;
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(vec_vec[0][i], expected_inner_vec1[i]);
        EXPECT_EQ(vec_vec[1][i], expected_inner_vec2[i]);
    }
}




TEST(VectorTest, Test_pop) {

}

TEST(VectorTest, Test_operator_equality) {
    int arr[5] = {1,2,3,4,5};
    MyVector<int> int_vec2;
}