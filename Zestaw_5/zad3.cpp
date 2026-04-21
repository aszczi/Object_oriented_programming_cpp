#include <iostream>
#include <type_traits>
#include <string>

/*Zaimplementuj szablon klasy Is_convertible za pomocą którego możliwe jest stwierdzenie czy jeden z typów można rzutować na drugi.*/

template<typename From, typename To>
struct Is_convertible {
private:
    static void check(To);

    template<typename F, typename = decltype(check(std::declval<F>()))>
    static std::true_type test(int);
    template<typename>
    static std::false_type test(...);

public:
    static constexpr bool value = decltype(test<From>(0))::value;
};

int main() {
    std::cout << std::boolalpha;
    std::cout << "int -> double:       " << Is_convertible<int, double>::value << std::endl; //true
    std::cout << "int* -> double:      " << Is_convertible<int*, double>::value << std::endl; //false
    std::cout << "const int& -> int:   " << Is_convertible<const int&, int>::value << std::endl; //true
    std::cout << "const char* -> string: " << Is_convertible<const char*, std::string>::value << std::endl; //true

    return 0;
}