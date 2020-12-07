#include "doctest/doctest.h"

#include "../include/isto/units/units.hpp"
    using namespace isto::units;

#include "../include/isto/units/quantity_fmt.hpp"
#include "../include/isto/units/dimension_fmt.hpp"

TEST_CASE("units")
{
    SUBCASE("functions")
    {
            constexpr auto
        x = 4. * unit::metre <>;
            constexpr auto
        y = pow <2> (x);
        static_assert (y.dimension == dimension::area);
        static_assert (y.magnitude == 16.0);
            constexpr auto
        z = pow <0.5> (y);
        static_assert (z.dimension == dimension::length);
        static_assert (z.magnitude == 4.0);
        static_assert (z == x);
            constexpr auto
        a = 4. * pow <2> (unit::metre <>) / pow <2> (unit::second <>);
        static_assert (a.dimension == pow <2> (dimension::length / dimension::time));
        static_assert (a.magnitude == 4.0);
            constexpr auto
        b = pow <0.5> (a);
        static_assert (b.dimension == dimension::length / dimension::time);
        static_assert (b.magnitude == 2.0);
            constexpr auto
        c = sqrt (a);
        static_assert (c.dimension == dimension::length / dimension::time);
        static_assert (c.magnitude == 2.0);
    }
    SUBCASE("dimensions")
    {
            constexpr auto
        a = dimension::length * dimension::length;
            constexpr auto
        b = pow <0.5> (a);
        static_assert (b == dimension::length);
            constexpr auto
        c = dimension::none / dimension::length / dimension::length;
            constexpr auto
        d = pow <0.5> (c);
        static_assert (d == dimension::none / dimension::length);
    }
    SUBCASE("literals")
    {
            using namespace unit::literals;
        static_assert (1.0_m == unit::metre <long double>);
        static_assert (1000.0_MPa == unit::gigapascal <long double>);
    }
    SUBCASE("dimensionless")
    {
            constexpr auto
        a = 4. * unit::metre <> * unit::second <>;
            constexpr auto
        b = 2. * unit::metre <> * unit::second <>;
            constexpr auto
        c = a / b;
        static_assert (std::is_same_v <decltype (c), const double>);
    }
    SUBCASE("concepts")
    {
        static_assert (concepts::pressure <decltype (unit::pascal <>)>);
    }
};
