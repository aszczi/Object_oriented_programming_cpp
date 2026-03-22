#include <iostream>
#include <set>

template <typename Iter>
void ReverseSort(Iter x, Iter y) {
    while (x != y) {
        std::cout << *x << " ";
        ++x;
    }
}

int main() {
    std::set<int, std::greater<>> set;

    set.insert(1);
    set.insert(2);
    set.insert(3);

    ReverseSort(set.begin(), set.end());

    return 0;
}