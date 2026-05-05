#include <iostream>

template<int M>
struct FastPow {
    template<typename T>
    static T calc(T x) {
        if constexpr (M == 0) {
            return T{1};
        } else if constexpr (M == 1) {
            return x;
        } else {
            T half = FastPow<M / 2>::calc(x);

            if constexpr (M % 2 == 0)
                return half * half;
            else
                return half * half * x;
        }
    }
};

int main() {
    double x = 2.0;


    clock_t start = clock();
    std::cout << "3^10 = " << FastPow<10>::calc(3.0) << '\n';
    std::cout << "2^16 = " << FastPow<16>::calc(x) << '\n';

    clock_t stop = clock();
    double time_taken = double(stop - start) / CLOCKS_PER_SEC;
    std::cout << "Czas wykonania: " << time_taken << " s" << std::endl;

    return 0;
}