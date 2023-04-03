#ifndef TRANSFORM_TYPELISTS_HPP
#define TRANSFORM_TYPELISTS_HPP

#include <type_traits>

namespace typelists {
    template<template<typename > typename Projection, typename TList>
    struct transform_typelists;

    template<template<typename > typename Projection, template<typename... > typename TList, typename... Ts>
    struct transform_typelists<Projection, TList<Ts...>> : std::type_identity<TList<Projection<Ts>...>> {};

}
#endif
