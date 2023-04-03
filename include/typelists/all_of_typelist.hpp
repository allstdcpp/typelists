#ifndef ALL_OF_TYPELIST
#define ALL_OF_TYPELIST

#include <type_traits>

namespace typelists {

    template<template<typename> typename Predicate, class TList>
    struct all_of_typelist;

    template<template<typename> typename Predicate, template<typename...> class TList>
    struct all_of_typelist<Predicate, TList<>> : std::true_type {};

    template<template<typename> typename Predicate, template<typename...> class TList, typename T>
    struct all_of_typelist<Predicate, TList<T>> : Predicate<T>  {};

    template<template<typename> typename Predicate, template<typename...> class TList, typename T, typename... Ts>
    struct all_of_typelist<Predicate, TList<T, Ts...>> : std::conditional_t<!Predicate<T>::value,
                                                                            std::false_type,
                                                                            all_of_typelist<Predicate, TList<Ts...>>> {};

}

#endif
