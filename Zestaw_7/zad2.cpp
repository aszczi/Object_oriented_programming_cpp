#include <iostream>
#include <ctime>
template<int N, int M>
struct Pow {
    static constexpr int value = N * Pow<N, M - 1>::value;
};

template<int N>
struct Pow<N, 0> {
    static constexpr int value = 1;
};

int main() {
    clock_t start = clock();

    std::cout << "3^10 = " << Pow<3, 10>::value << '\n';
    std::cout << "2^16 = " << Pow<2, 16>::value << '\n';

    clock_t stop = clock();
    double time_taken = double(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas wykonania: " << time_taken << " s" << std::endl;
    return 0;
}