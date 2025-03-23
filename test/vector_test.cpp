#include <gtest/gtest.h>
#include "my_vector.h"

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
}