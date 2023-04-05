#include <typelists/unique.hpp>
#include <catch.hpp>

TEST_CASE("unique tests") {
    
    SECTION("similar types with different qualifiers") {
        REQUIRE(typelists::unique<int, double, float, const int>::value);
    }
    SECTION("no types") {
        REQUIRE(typelists::unique<>::value);
    }
    SECTION("single type") {
        REQUIRE(typelists::unique<int>::value);
    }
    SECTION("distinct types that are not sorted with no qualifiers") {
        REQUIRE(typelists::unique<int, double, float, int>::value);
    }
    SECTION("distinct sorted types with no qualifiers") {
        REQUIRE_FALSE(typelists::unique<int,int, double, float>::value);
    }
}
