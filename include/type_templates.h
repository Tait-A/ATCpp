#ifndef TYPE_TEMPLATES_H
#define TYPE_TEMPLATES_H

#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template <typename T>
const char* type_name() {
    return "Unknown Type";
}

template <>
const char* type_name<int>() {
    return "int";
}

template <>
const char* type_name<float>() {
    return "float";
}

template <>
const char* type_name<double>() {
    return "double";
}

template <>
const char* type_name<std::string>() {
    return "std::string";
}

template <typename T>
std::enable_if_t<std::is_pointer_v<T>, const char*>
type_name() {
    using PointeeType = std::remove_pointer_t<T>;
    static std::string result = std::string("Pointer to ") + type_name<PointeeType>();
    return result.c_str();
}

template <typename T>
const char* type_name(std::vector<T> const&) {
    static std::string result = std::string("std::vector<") + type_name<T>() + ">";
    return result.c_str();
}

template <typename T>
std::enable_if_t<!std::is_same_v<typename T::value_type, void>, const char*>
type_name(T const&) {
    static std::string result = std::string("Unknown container of ") + type_name<typename T::value_type>();
    return result.c_str();
}

#endif // TYPE_TEMPLATES_H
