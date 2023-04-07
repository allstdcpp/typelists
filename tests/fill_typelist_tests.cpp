#include <typelists/fill_typelist.hpp>
#include <typelists/type_list.hpp>
#include <catch.hpp>

TEST_CASE("fill_typelist tests") {

    SECTION("fill with 3 ints") {
        using result_t = typelists::fill_typelist<int,3>::type;
        REQUIRE(std::is_same<typelists::type_list<int,int,int>, result_t>::value);
    }

    SECTION("fill with 1 ints") {
        using result_t = typelists::fill_typelist<int,1>::type;
        REQUIRE(std::is_same<typelists::type_list<int>, result_t>::value);
    }

    SECTION("fill with 0 ints") {
        using result_t = typelists::fill_typelist<int,0>::type;
        REQUIRE(std::is_same<typelists::type_list<>, result_t>::value);
    }
}

