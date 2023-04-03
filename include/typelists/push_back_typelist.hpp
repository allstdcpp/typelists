#ifndef PUSH_BACK_TYPELIST_HPP
#define PUSH_BACK_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<typename T, typename TList>
    struct push_back;

    template<typename T, template<typename...> typename TList, typename... Ts>
    struct push_back<T, TList<Ts...>> : std::type_identity<TList<Ts...,T>> {};
}

#endif
