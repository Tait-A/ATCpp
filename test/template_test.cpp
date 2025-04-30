#include <gtest/gtest.h>
#include "type_templates.h"
#include <string>
#include <vector>
#include <iostream>

TEST(TypeNameTest, TestTypeName) {
    EXPECT_STREQ(type_name<int>(), "int");
    EXPECT_STREQ(type_name<float>(), "float");
    EXPECT_STREQ(type_name<double>(), "double");
    EXPECT_STREQ(type_name<std::string>(), "std::string");
    // EXPECT_STREQ(type_name<std::vector<int>>(), "std::vector<int>");
}