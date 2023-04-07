#ifndef FILL_TYPELIST_HPP
#define FILL_TYPELIST_HPP

#include <typelists/type_list.hpp>
#include <type_traits>

namespace typelists {

    namespace detail {

        template<typename T, size_t N, typename TList>
        struct fill_typelist_;

        template<typename T, template<typename... > class TList, typename... Ts>
        struct fill_typelist_<T, 0, TList<Ts...>> : std::type_identity<TList<Ts...>> {};

        template<typename T, size_t N, template<typename... > class TList, typename... Ts>
        struct fill_typelist_<T, N, TList<Ts...>> : fill_typelist_<T, (N - 1), TList<T, Ts...>> {};
    }
    
    template<typename T, size_t N>
    struct fill_typelist : detail::fill_typelist_<T, N, typelists::type_list<>> {};

}

#endif
