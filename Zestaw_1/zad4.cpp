#include <iostream>

template <int N>
struct Struktura {};

template <template <int> class C, int K>
void f(C<K> obj) {
    std::cout << "K: " << K << std::endl;
}