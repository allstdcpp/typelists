#ifndef COUNT_HPP
#define COUNT_HPP

#include <type_traits>

namespace typelists {

    template<template<typename> typename Predicate, typename... Ts>
    struct count;

    template<template<typename> typename Predicate>
    struct count<Predicate> : std::integral_constant<int, 0>{};

    template<template<typename> typename Predicate, typename T, typename... Ts>
    struct count<Predicate, T, Ts...> : std::conditional_t<!Predicate<T>::value,
                                                            count<Predicate,Ts...>,
                                                            std::integral_constant<int, 1 + count<Predicate, Ts...>::value>>{};
}

#endif
