#include <iostream>

template<typename T,int N = 100> class Stack {
    public:
        Stack()= default;
};

template<typename T> class Stack<T,666> {
public:
    Stack() = default;
};

template<typename T,int N> class Stack<T*,N> {
public:
    Stack() = default;
};

template<int N> class Stack<double ,N> {
public:
    Stack() = default;
};

template<int N> class Stack<int *,N> {
public:
    Stack() = default;
};

template<> class Stack<double,666> {
public:
    Stack() = default;
};

template<> class Stack<double *,44> {
public:
    Stack() = default;
};

int main() {

    std::cout << typeid(Stack<int, 666>).name() << std::endl;
    std::cout << typeid(Stack<float *, 20>).name() << std::endl;
    std::cout << typeid(Stack<double, 30>).name() << std::endl;
    std::cout << typeid(Stack<int *, 40>).name() << std::endl;
    std::cout << typeid(Stack<double, 666>).name() << std::endl;
    std::cout << typeid(Stack<double *, 44>).name() << std::endl;

    return 0;
}