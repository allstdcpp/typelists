#ifndef UNIQUE_HPP
#define UNIQUE_HPP

#include <type_traits>

namespace typelists {

    template<typename... Ts>
    struct unique;

    template<typename T>
    struct unique<T> : std::true_type {};

    template<typename T, typename... Ts>
    struct unique<T, T, Ts...> : std::false_type{};

    template<typename T, typename U, typename... Rest>
    struct unique<T, U, Rest...> : unique<U, Rest...>{};
}
#endif
