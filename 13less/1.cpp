#include <iostream>

// operator , (T, T)


template <typename T>
struct has_less_or_equal_operator {
    private:
        static int detect(...);

    template <typename U>
    static auto detect(const U&, const U&) -> decltype(std::declval<U>() == std::declval<U>(), bool());
public:
    static constexpr bool value = std::is_same<bool, decltype(detect(declval<T>(), declval<T>()))>::value;
};

