#include <iostream>
#include <string>

/* Zaimplementuj szablon is_class służący do sprawdzania czy dany typ jest klasą.*/

template<typename T>
struct is_class {
private:
    template<typename C>
    static char test(int C::*);

    template<typename C>
    static int test(...);

public:
    static constexpr bool value = (sizeof(test<T>(nullptr)) == sizeof(char));
};

class Test_class {};
struct Test_struct {};

int main() {
    std::cout << std::boolalpha;
    std::cout << "Test_class:   " << is_class<Test_class>::value << std::endl;   // true
    std::cout << "Test_struct:  " << is_class<Test_struct>::value << std::endl;  // true
    std::cout << "int:          " << is_class<int>::value << std::endl;          // false
    std::cout << "float:        " << is_class<float>::value << std::endl;        // false
    std::cout << "std::string:  " << is_class<std::string>::value << std::endl;  // true
    std::cout << "const char*:  " << is_class<const char*>::value << std::endl;  // false
    
    return 0;
}