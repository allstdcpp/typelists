#ifndef ASSIGN_TYPELIST_HPP
#define ASSIGN_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<typename TSourceList, typename TDestList>
    struct assign_typelist;

    template<template<typename...> typename TSourceList, template<typename... > typename TDestList, typename... Ts, typename... Us>
    struct assign_typelist<TSourceList<Ts...>, TDestList<Us...>> : std::type_identity<TSourceList<Ts...>> {};
}

#endif
