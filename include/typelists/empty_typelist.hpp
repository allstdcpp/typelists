#ifndef EMPTY_TYPELIST_HPP
#define EMPTY_TYPELIST_HPP

#include <type_traits>

namespace typelists {
    
    template<typename TList>
    struct empty_typelist;

    template<template<typename...> typename TList, typename... Ts>
    struct empty_typelist<TList<Ts...>> : std::false_type{};

    template<template<typename...> typename TList>
    struct empty_typelist<TList<>> : std::true_type{};
}

#endif
