#include <iostream>
#include <cstring>

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
T* max(T* a, T* b) {
    return (*a > *b) ? a : b;
}

template<typename T>
T max(T* data, size_t n) {
    T _max = data[0];
    for (size_t i = 1; i < n; i++)
        if (data[i] > _max) _max = data[i];
    return _max;
}

char* max(char* a, char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

const char* max(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

const char* max(char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

int main() {
    int i = 6, j = 7;
    double x[5] = {5, 9, 2, 8, 3};

    char* p1 = new char[6];
    char* p2 = new char[6];

    strncpy(p1, "cat", 6);
    strncpy(p2, "dog", 6);

    std::cout << max(i, j) << std::endl;
    std::cout << *max(&i, &j) << std::endl;
    std::cout << max(x, 5) << std::endl;
    std::cout << max("cat", "dog") << std::endl;
    std::cout << max(p1, p2) << std::endl;
    std::cout << max(p1, "cat") << std::endl;

    delete[] p1;
    delete[] p2;

    return 0;
}