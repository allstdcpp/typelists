#ifndef EMPTY_HPP
#define EMPTY_HPP

#include <type_traits>

namespace typelists {

    template<typename... Ts>
    struct empty : std::false_type {};

    template<>
    struct empty<> : std::true_type {};
}

#endif
