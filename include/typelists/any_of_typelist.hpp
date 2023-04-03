#ifndef ANY_OF_TYPELIST
#define ANY_OF_TYPELIST

#include <type_traits>

namespace typelists {

    template<template<typename> typename Predicate, class TList>
    struct any_of_typelist;

    template<template<typename> typename Predicate, template<typename...> class TList>
    struct any_of_typelist<Predicate, TList<>> : std::true_type {};

    template<template<typename> typename Predicate, template<typename...> class TList, typename T>
    struct any_of_typelist<Predicate, TList<T>> : Predicate<T>  {};

    template<template<typename> typename Predicate, template<typename...> class TList, typename T, typename... Ts>
    struct any_of_typelist<Predicate, TList<T, Ts...>> : std::conditional_t<Predicate<T>::value,
                                                                            std::true_type,
                                                                            any_of_typelist<Predicate, TList<Ts...>>> {};

}

#endif
