template <typename StackType>
typename StackType::value_type suma_stos(StackType s) {
    typename StackType::value_type suma = 0;

    while (!s.is_empty()) {
        suma += s.pop();
    }

    return suma;
}