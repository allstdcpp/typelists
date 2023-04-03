#ifndef COUNT_TYPELIST_HPP
#define COUNT_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<template<typename> typename Predicate, typename TList>
    struct count_typelist;

    template<template<typename> typename Predicate, template<typename... > typename TList>
    struct count_typelist<Predicate, TList<>> : std::integral_constant<int, 0>{};

    template<template<typename> typename Predicate, template<typename...> typename TList, typename T, typename... Ts>
    struct count_typelist<Predicate, TList<T, Ts...>> : std::conditional_t<!Predicate<T>::value,
                                                            count_typelist<Predicate,Ts...>,
                                                            std::integral_constant<int, 1 + count_typelist<Predicate, TList<Ts...>>::value>>{};
}

#endif
