template <int N, typename T>
T dot_product(T* x, T* y) {
    T suma = T();
    for (int i = 0; i < N; i++) {
        suma += x[i] * y[i];
    }
    return suma;
}