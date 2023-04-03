#ifndef PUSH_FRONT_TYPELIST_HPP
#define PUSH_FRONT_TYPELIST_HPP

#include <type_traits>

namespace typelists {

    template<typename T, typename TList>
    struct push_front;

    template<typename T, template<typename...> typename TList, typename... Ts>
    struct push_front<T, TList<Ts...>> : std::type_identity<TList<T, Ts...>> {};
}

#endif
