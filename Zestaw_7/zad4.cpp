#include <iostream>
#include <utility>

constexpr double ct_pow(double x, int n) {
    double res = 1.0;
    for (int i = 0; i < n; ++i) res *= x;
    return res;
}

constexpr double ct_fact(int n) {
    double res = 1.0;
    for (int i = 1; i <= n; ++i) res *= i;
    return res;
}

template <size_t... I>
constexpr double sin_impl(double x, std::index_sequence<I...>) { // C++17 Fold Expression
    return (((I % 2 == 0 ? 1.0 : -1.0) * ct_pow(x, 2 * I + 1) / ct_fact(2 * I + 1)) + ...);
}

template <size_t N>
constexpr double taylor_sin(double x) {
    return sin_impl(x, std::make_index_sequence<N>{});
}

int main() {
    double x = 3.14159265 / 6.0; // ok. 30 stopni, sin(30) = 0.5
    std::cout << "sin(30 stopni) = " << taylor_sin<5>(x) << "\n";
    return 0;
}