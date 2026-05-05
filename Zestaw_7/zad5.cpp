#include <iostream>

template<size_t N> 
double inner(double *x, double *y) {
    if constexpr (N == 0) {
        return 0.0;
    } else {
        return (*x) * (*y) + inner<N - 1>(x + 1, y + 1);
    }
}

int main() {
    double vec1[] = {1.0, 2.0, 3.0};
    double vec2[] = {4.0, 5.0, 6.0};

    std::cout << "Iloczyn skalarny: " << inner<3>(vec1, vec2) << "\n";
    
    return 0;
}