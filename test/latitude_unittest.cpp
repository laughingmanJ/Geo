#include "gtest/gtest.h"
#include "latitude.hpp"
#include <stdexcept>

TEST(Latitude, DDecimalConstructor)
{
	constexpr double test_value = 37.4555;
	const geo::Latitude lat(test_value);
	
	ASSERT_DOUBLE_EQ(lat.decimal_degrees(), test_value);
}

TEST(Latitude, DDecimalConstructorFail)
{
	ASSERT_THROW(
		geo::Latitude lat(-91.0),
		std::invalid_argument
	);

	ASSERT_THROW(
		geo::Latitude lat(90.000001),
		std::invalid_argument
	);
}

TEST(Latitude, DMSConstructor)
{
	// TODO
}

TEST(Latitude, DMSConstructorFail)
{
	// TODO
}

TEST(Latitude, DirectionNorth)
{
	const geo::Latitude lat1(10.0);
	ASSERT_EQ(geo::Direction::N, lat1.direction());

	const geo::Latitude lat2(0.0);
	ASSERT_EQ(geo::Direction::N, lat2.direction());
}

TEST(Latitude, DirectionSouth)
{
	const geo::Latitude lat(-0.5);
	ASSERT_EQ(geo::Direction::S, lat.direction());
}

TEST(Latitude, Equals)
{
	// Test to make sure equal within 6 decimal places.
	const geo::Latitude lat1(-11.56311411);
	const geo::Latitude lat2(-11.56311422);

	ASSERT_TRUE(lat1 == lat2);
}

TEST(Latitude, NotEquals)
{
	// TODO
}

TEST(Latitude, ToString)
{
	// TODO
}