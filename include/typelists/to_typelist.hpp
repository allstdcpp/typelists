#ifndef TO_TYPLIST_HPP
#define TO_TYPLIST_HPP

#include <type_traits>
#include <typelists/type_list.hpp>

namespace typelists {
    template<typename... Ts>
    struct to_typelist : std::type_identity<type_list<Ts...>> {};
}

#endif
