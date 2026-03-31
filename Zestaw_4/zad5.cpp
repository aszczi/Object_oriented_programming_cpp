#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

using namespace std;

template <typename Iter>
int perform(Iter i, std::random_access_iterator_tag) {
    cout << "random_access_iterator" << endl;
    return 1;
}

template <typename Iter>
int perform(Iter i, std::bidirectional_iterator_tag) {
    cout << "bidirectional_iterator" << endl;
    return 2;
}

template <typename Iter>
int perform(Iter i, std::forward_iterator_tag) {
    cout << "forward_iterator" << endl;
    return 3;
}

template <typename Iter>
inline int operation(Iter i) {
    return perform(i, typename std::iterator_traits<Iter>::iterator_category());
}

int main() {
    vector<int> v;
    list<int> l;
    forward_list<int> fl;
    int arr[5];

    operation(v.begin());
    operation(l.begin());
    operation(fl.begin());
    operation(arr);

    return 0;
}