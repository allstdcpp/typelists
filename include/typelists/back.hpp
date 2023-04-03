#ifndef BACK_HPP
#define BACK_HPP

#include <type_traits>

namespace typelists {
    template<typename... Ts>
    struct back;

    template<typename T>
    struct back<T> : std::type_identity<T> {};

    template<typename T, typename... Ts>
    struct back<T, Ts...> : back<Ts..>{};

}
#endif
