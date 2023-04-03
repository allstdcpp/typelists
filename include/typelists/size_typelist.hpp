#ifndef SIZE_TYPELIST_HPP
#define SIZE_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<typename TList>
    struct size;

    template<template<typename...> typename TList>
    struct size<TList<>> : std::integral_constant<int, 0>{};

    template<template<typename...> typename TList, typename T, typename... Ts>
    struct size<TList<T, Ts...>> : std::integral_constant<int, 1 + size<TList<Ts...>>::value> {};

}

#endif
