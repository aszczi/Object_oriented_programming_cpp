#include <iostream>

using namespace std;

template <typename T>
struct sum_traits;

template <> struct sum_traits<char> { 
    typedef int sum_type; 
    static sum_type zero() { return 0; } 
};
template <> struct sum_traits<int> { 
    typedef int sum_type; 
    static sum_type zero() { return 0; } 
};
template <> struct sum_traits<float> { 
    typedef double sum_type; 
    static sum_type zero() { return 0.0; } 
};
template <> struct sum_traits<double> { 
    typedef double sum_type; 
    static sum_type zero() { return 0.0; } 
};

template<typename T>
typename sum_traits<T>::sum_type sum(T* begin, T* end) {
    typename sum_traits<T>::sum_type total = sum_traits<T>::zero();
    
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

int main() {
    float arr[] = { 5.5, 6.3, 8.2 };
    cout << "Suma float: " << sum(arr, arr + 3) << endl; 
    return 0;
}