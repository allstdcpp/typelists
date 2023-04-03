#ifndef FRONT_HPP
#define FRONT_HPP

#include <type_traits>

namespace typelists {

    template<typename... Ts>
    struct front;

    template<typename T, typename... Ts>
    struct front<T, Ts...> : std::type_identity<T> {};
}

#endif
