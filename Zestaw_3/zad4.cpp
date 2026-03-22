#include <iostream>
#include <vector>

template <typename T, int N = 100, typename R = T *> class Stack;

template <typename T, int N> class Stack<T, N, T *> {
public:
    Stack() = default;
    std::vector<T> s;

    void push(const T &t) { s.push_back(t); }

    T pop() {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }
    bool empty() const { return s.empty(); }
    size_t size() const { return s.size(); }
};

template <typename T, int N> class Stack<T, N, std::vector<T>> {
public:
    Stack() = default;
    std::vector<T> s;
    void push(const T &t) {
        s.push_back(t);
    }

    T pop() {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }
    bool empty() const { return s.empty(); }
    size_t size() const { return s.size(); }
};

template <typename T, int N> class Stack<T, N, std::vector<T> &> {
public:
    Stack() = default;
    std::vector<T> &s;
    void push(const T &t) {
        s.push_back(t);
    }

    T pop() {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }
    bool empty() const { return s.empty(); }
    size_t size() const { return s.size(); }
};

int main() {
    Stack<int, 100> first_stack;
    Stack<int, 0, std::vector<int>> second_stack;

    first_stack.push(9);
    first_stack.push(8);
    std::cout << first_stack.pop() << std::endl;
    std::cout << first_stack.pop() << std::endl;

    second_stack.push(7);
    second_stack.push(6);
    std::cout << second_stack.pop() << std::endl;
    std::cout << second_stack.pop() << std::endl;
}