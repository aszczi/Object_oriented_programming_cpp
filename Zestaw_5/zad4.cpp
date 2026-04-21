#include <iostream>
#include <type_traits>

/*Zdefiniuj szablon Strip, który jako funkcja typów dokonuje operacji usunięcia
 jednego lub obydwu kwalifikatorów (const oraz &) i uzyskanie gołego typu podstawowego.*/

template<typename T>
struct Strip {
    using type = typename std::remove_const<typename std::remove_reference<T>::type>::type;
};
template<typename T>
using Strip_t = typename Strip<T>::type;

int main() {
    std::cout << std::boolalpha;

    using T1 = const int;
    using T1_stripped = Strip<T1>::type; 
    std::cout << "const int -> int:     " << std::is_same<T1_stripped, int>::value << "\n"; // true
    using T2 = int&;
    using T2_stripped = Strip<T2>::type; 
    std::cout << "int& -> int:          " << std::is_same<T2_stripped, int>::value << "\n"; // true
    using T3 = const int&;
    using T3_stripped = Strip<T3>::type; 
    std::cout << "const int& -> int:    " << std::is_same<T3_stripped, int>::value << "\n"; // true
    std::cout << "Alias Strip_t:        " << std::is_same<Strip_t<const double&>, double>::value << "\n"; // true

    return 0;
}