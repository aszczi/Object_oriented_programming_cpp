#include<iostream>

template<typename T, size_t N = 10>
class Dynamic_allocator_inh {
protected:
    T* _rep;
    size_t _capacity = N;

    void init() { _rep = new T[_capacity]; }
    void dealocate() { delete[] _rep; }

    void expand_if_needed(size_t current_size) {
        if (current_size == _capacity) {
            std::cout << " [Alokator 2] Brak miejsca! Powiekszanie " << _capacity << " -> " << _capacity*2 << "\n";
            _capacity *= 2;
            T* new_rep = new T[_capacity];
            for (size_t i = 0; i < current_size; ++i) new_rep[i] = _rep[i];
            delete[] _rep;
            _rep = new_rep;
        }
    }
};

template<typename T, size_t N = 10, template<typename, size_t> class Allocator = Dynamic_allocator_inh>
class StackInh : private Allocator<T, N> {
private:
    size_t _top = 0;

public:
    StackInh()  { this->init(); }
    ~StackInh() { this->dealocate(); }

    void push(const T& val) {
        this->expand_if_needed(_top);
        this->_rep[_top++] = val;
    }
    void pop() { --_top; }
    T& top()   { return this->_rep[_top - 1]; }
};

int main(){

    StackInh<double, 2> mojStos2;

    std::cout << "Dodawanie 3.14\n"; mojStos2.push(3.14);
    std::cout << "Dodawanie 2.71\n"; mojStos2.push(2.71);
    std::cout << "Dodawanie 1.61\n"; mojStos2.push(1.61);
    std::cout << "Na gorze jest teraz: " << mojStos2.top() << "\n";
    mojStos2.pop();
    std::cout << "Po zdjeciu elementu, na gorze jest: " << mojStos2.top() << "\n";

  return 0;
  }