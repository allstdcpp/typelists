#ifndef ERASE_TYPELIST_HPP
#define ERASE_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<typename TSourceList>
    struct erase_typelist;

    template<template<typename...> typename TSourceList, typename... Ts>
    struct erase_typelist<TSourceList<Ts...>>: std::type_identity<TSourceList<>> {};
}

#endif
