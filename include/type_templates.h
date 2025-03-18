template <typename T>
const char* type_name() {
    return "Unknown Type";
}

template <>
const char* type_name<int>() {
    return "int";
}