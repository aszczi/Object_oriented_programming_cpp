#include <iostream>

template<typename T, size_t N = 10>
struct Dynamic_table_allocator {
    typedef T* rep_type;
    size_t capacity = N;

    void init(rep_type &rep, size_t) { rep = new T[capacity]; }
    void dealocate(rep_type &rep) { delete[] rep; }

    void expand_if_needed(rep_type &rep, size_t current_size) {
        if (current_size == capacity) {
            std::cout << " [Alokator 1] Brak miejsca! Powiekszanie " << capacity << " -> " << capacity*2 << "\n";
            capacity *= 2;
            T* new_rep = new T[capacity];
            for (size_t i = 0; i < current_size; ++i) new_rep[i] = rep[i];
            delete[] rep;
            rep = new_rep;
        }
    }
};

template<typename T, size_t N = 10, template<typename, size_t> class Allocator = Dynamic_table_allocator>
class Stack {
private:
    Allocator<T, N> _allocator;
    T* _rep;
    size_t _top = 0;

public:
    Stack()  { _allocator.init(_rep, N); }
    ~Stack() { _allocator.dealocate(_rep); }

    void push(const T& val) {
        _allocator.expand_if_needed(_rep, _top);
        _rep[_top++] = val;
    }
    void pop() { --_top; }
    T& top()   { return _rep[_top - 1]; }
};



int main() {

    Stack<int, 2> mojStos1;
    std::cout << "Dodawanie 10\n"; mojStos1.push(10);
    std::cout << "Dodawanie 20\n"; mojStos1.push(20);
    std::cout << "Dodawanie 30\n"; mojStos1.push(30);
    std::cout << "Na gorze jest teraz: " << mojStos1.top() << "\n";
    mojStos1.pop();
    std::cout << "Po zdjeciu elementu, na gorze jest: " << mojStos1.top() << "\n\n";

    return 0;
}