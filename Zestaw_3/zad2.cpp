#include <iostream>
#include <string>

template<typename T>
T convert(int int_convert, int int_convert_v2);

template<>
int convert<int>(int int_convert, int int_convert_v2) {
    return int_convert_v2 + int_convert;
}

template<>
std::string convert<std::string>(int int_convert, int int_convert_v2) {
    int sum =  int_convert_v2 + int_convert;
    return "sum is equal: " + std::to_string(sum);
}

int main() {

    int first = convert<int>(1, 2);
    std::string second = convert<std::string>(1, 2);

    std::cout << "Result int: " << first << std::endl;
    std::cout << "Result string: " << second << std::endl;

    return 0;
}