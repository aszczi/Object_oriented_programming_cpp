#include <iostream>

//statyczny
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

//dynamiczny
class Animal { //abstract
public:
    virtual ~Animal() = default;
    virtual void speak() const = 0;
};

class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Hau hau!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Miau miau!" << std::endl;
    }
};

int main() {
    std::cout << "Polimorfizm statyczny" << std::endl;
    Calculator calc;
    std::cout << "Suma int: " << calc.add(5, 10) << std::endl;
    std::cout << "Suma double: " << calc.add(3.5, 2.1) << std::endl;

    std::cout << "\nPolimorfizm dynamiczny" << std::endl;
    Dog dog;
    Cat cat;

    Animal* animal1 = &dog;
    Animal* animal2 = &cat;

    animal1->speak();
    animal2->speak();

    return 0;
}