#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

/*  Napisz szablon, który sprawdza czy jego parametr posiada typ stowarzyszony value_type,
    np.: has_value_type<std::vector<int> >::yes powinno mieć wartość true, a has_value_type<int>::yes wartość false.*/

template <typename T>
struct has_value_type {
private:
    template<typename C>
    static std::true_type test(typename C::value_type*);

    template<typename C>
    static std::false_type test(...);

public:
    static constexpr bool yes = decltype(test<T>(nullptr))::value;
};

int main() {
    std::cout << std::boolalpha;
    
    std::cout << "std::vector<int>: " << has_value_type<std::vector<int>>::yes << std::endl; // true
    std::cout << "int:              " << has_value_type<int>::yes << std::endl;          // false
    std::cout << "double*:          " << has_value_type<double*>::yes << std::endl;      // false
    std::cout << "std::string:      " << has_value_type<std::string>::yes << std::endl;  // true

    return 0;
}