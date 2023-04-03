#ifndef POPFRONT_TYPELISTS_HPP
#define POPFRONT_TYPELISTS_HPP

#include <type_traits>

namespace typelists {

    template<typename TList>
    struct pop_front_typelist;

    template<template<typename... > typename TList, typename T, typename... Ts>
    struct pop_front_typelist<TList<T, Ts...>> : std::type_identity<TList<Ts...>> {};

}
#endif
