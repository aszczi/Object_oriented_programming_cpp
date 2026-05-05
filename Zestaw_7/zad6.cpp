#include <iostream>

template<size_t N, typename T> 
T dot(T *x, T *y) {
    if constexpr (N == 0) {
        return T{0}; 
    } else {
        return (*x) * (*y) + dot<N - 1, T>(x + 1, y + 1);
    }
}

int main() {
    int vec1[] = {2, 3, 4};
    int vec2[] = {5, 6, 7};
    
    float vec3[] = {1.5f, 2.5f};
    float vec4[] = {2.0f, 4.0f};
    
    std::cout << "Iloczyn skalarny (int): " << dot<3, int>(vec1, vec2) << "\n";
    std::cout << "Iloczyn skalarny (float): " << dot<2, float>(vec3, vec4) << "\n";
    
    return 0;
}