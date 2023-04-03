#ifndef UNIQUE_TYPELIST_HPP
#define UNIQUE_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<typename TList>
    struct unique_typelist;

    template<template<typename...> typename TList>
    struct unique_typelist<TList<>> : std::true_type {};

    template<template<typename ...> typename TList, typename T, typename... Ts>
    struct unique_typelist<TList<T, T, Ts...>> : std::false_type{};

    template<template<typename...> typename TList, typename T, typename U, typename... Rest>
    struct unique_typelist<TList<T, U, Rest...>> : unique_typelist<TList<U, Rest...>>{};
}

#endif
