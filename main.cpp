#include <typelists/all_of.hpp>
#include <typelists/any_of.hpp>
#include <typelists/count.hpp>
#include <typelists/all_of_typelist.hpp>
#include <typelists/type_list.hpp>
#include <iostream>

int main(int argc, char** argv) {

    using namespace typelists;

    constexpr auto all_const = all_of<std::is_const, const int, const double, const float>::value;
    std::cout << "all const: " << all_const << std::endl;

    constexpr auto any_const = any_of<std::is_const, const int, const double, const float>::value;
    std::cout << "any const: " << any_const << std::endl;

    constexpr auto all_const_ = all_of<std::is_const, int, const double, const float>::value;
    std::cout << "all const: " << all_const_ << std::endl;

    constexpr auto any_const_ = any_of<std::is_const, int, const double, const float>::value;
    std::cout << "any const: " << any_const_ << std::endl;

    constexpr auto count_const_ = count<std::is_const, int, const double, const float>::value;
    std::cout << "count const: " << count_const_ << std::endl;

    constexpr auto all_const_typelist = all_of_typelist<std::is_const, type_list<const int, const double, const float>>::value;
    std::cout << "all const: " << all_const_typelist << std::endl;

    constexpr auto all_const_typelist_ = all_of_typelist<std::is_const, type_list<int, const double, const float>>::value;
    std::cout << "all const: " << all_const_typelist_ << std::endl;

    return 0;
}
