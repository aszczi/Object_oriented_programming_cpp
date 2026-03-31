#include <iostream>

using namespace std;

template <typename T> struct sum_traits;
template <> struct sum_traits<char> { typedef int sum_type; static sum_type zero() { return 0; } };

struct sum_char {
    typedef char sum_type;
    static sum_type zero() { return '\0'; }
};

template<typename Traits, typename T>
typename Traits::sum_type sum(T* begin, T* end) {
    typename Traits::sum_type total = Traits::zero();
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

template<typename T>
typename sum_traits<T>::sum_type sum(T* begin, T* end) {
    return sum<sum_traits<T>, T>(begin, end);
}

int main() {
    char arr[] = {'a', 'b', 'c'};

    // int, czyli normalna suma 97 + 98 + 99 = 294
    cout << "Domyslna suma (typ int): " << sum(arr, arr + 3) << endl;

    // ASCII dla wartości 38 ('&')
    cout << "Wymuszona suma do char (znak): " << sum<sum_char>(arr, arr + 3) << endl;

    // wartosc & czyli 38
    cout << "Wymuszona suma do char (liczba): " << (int)sum<sum_char>(arr, arr + 3) << endl;
    
    return 0;
}