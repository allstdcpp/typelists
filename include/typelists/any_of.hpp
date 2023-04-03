#ifndef ANY_OF_HPP
#define ANY_OF_HPP

#include <type_traits>

namespace typelists {

    template<template<typename> typename Predicate, typename... Ts>
    struct any_of;

    template<template<typename> typename Predicate>
    struct any_of<Predicate> : std::true_type { };

    template<template<typename> typename Predicate, typename T>
    struct any_of<Predicate, T> : Predicate<T> {};

    template<template<typename> typename Predicate, typename T, typename... Ts>
    struct any_of<Predicate, T, Ts...> : std::conditional_t<Predicate<T>::value, 
                                                            std::true_type, any_of<Predicate, Ts...> > {};
}

#endif
