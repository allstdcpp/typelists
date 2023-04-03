#ifndef ALL_OF_HPP
#define ALL_OF_HPP

#include <type_traits>

namespace typelists {

    template<template<typename> typename Predicate, typename... Ts>
    struct all_of;

    template<template<typename> typename Predicate>
    struct all_of<Predicate> : std::false_type { };

    template<template<typename> typename Predicate, typename T>
    struct all_of<Predicate, T> : Predicate<T> {};

    template<template<typename> typename Predicate, typename T, typename... Ts>
    struct all_of<Predicate, T, Ts...> : std::conditional_t<!Predicate<T>::value, 
                                                            std::false_type, all_of<Predicate, Ts...> > {};
}

#endif
