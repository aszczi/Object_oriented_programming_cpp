#include <iostream>

template<int N>
struct Factorial {
    static constexpr int value = N * Factorial<N - 1>::value;
};

template<>
struct Factorial<0> {
    static constexpr int value = 1;
};

int main() {
    std::cout << "3! = " << Factorial<3>::value << '\n';
    std::cout << "4! = " << Factorial<4>::value << '\n';
    std::cout << "5! = " << Factorial<5>::value << '\n';
    return 0;
}