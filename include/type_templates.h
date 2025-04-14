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

