#include <iostream>

using namespace std;

template <typename T>
struct sum_traits;

template <> struct sum_traits<char>   { typedef int sum_type; };
template <> struct sum_traits<int>    { typedef int sum_type; };
template <> struct sum_traits<float>  { typedef double sum_type; };
template <> struct sum_traits<double> { typedef double sum_type; };

template<typename T>
typename sum_traits<T>::sum_type sum(T* begin, T* end) {
    typename sum_traits<T>::sum_type total = typename sum_traits<T>::sum_type();
    
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

int main() {
    char arr[] = "abcd"; // Kody ASCII: 97, 98, 99, 100
    cout << "Suma char: " << sum(arr, arr + 4) << endl; 
    return 0;
}