#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template <typename T> struct sum_traits;
template <> struct sum_traits<int> { typedef int sum_type; static sum_type zero() { return 0; } };

template<typename Traits, typename Iter>
typename Traits::sum_type sum(Iter begin, Iter end) {
    typename Traits::sum_type total = Traits::zero();
    while (begin != end) {
        total += *begin;
        ++begin;
    }
    return total;
}

template<typename Iter>
auto sum(Iter begin, Iter end) {
    typedef typename std::iterator_traits<Iter>::value_type val_type;

    return sum<sum_traits<val_type>, Iter>(begin, end);
}

int main() {
    vector<int> vec = { 15, 25, 35 };
    cout << "Suma vectora: " << sum(vec.begin(), vec.end()) << endl;

    int arr[] = { 1, 2, 3 };
    cout << "Suma tablicy: " << sum(arr, arr + 3) << endl;
    
    return 0;
}