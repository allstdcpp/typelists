#include <typelists/type_list.hpp>
#include <typelists/unique_typelist.hpp>
#include <catch.hpp>

TEST_CASE("unique_typelist tests") {

    SECTION("empty typelist") {
        REQUIRE(typelists::unique_typelist<typelists::type_list<>>::value);
    }

    SECTION("single typelist") {
        REQUIRE(typelists::unique_typelist<typelists::type_list<int>>::value);
    }

    SECTION("multiple sorted typelist") {
        REQUIRE_FALSE(typelists::unique_typelist<typelists::type_list<int,int,double,float>>::value);
    }

    SECTION("multiple sorted different qualifiers typelist") {
        REQUIRE(typelists::unique_typelist<typelists::type_list<int,const int,double,float>>::value);
    }

    SECTION("multiple unsorted typelist") {
        REQUIRE(typelists::unique_typelist<typelists::type_list<int,double,int,float>>::value);
    }
}
