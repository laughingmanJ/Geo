#include "gtest/gtest.h"
#include "functions.hpp"

TEST(Functions, GetDecimalDegrees1)
{
	// LAT 37° 19' 9.0" N 
	const geo::DMS dms_lat{37, 19, 9.0, true};

	// LON 122° 2' 42.4" W 
	const geo::DMS dms_lon{122,2,42.4, false};

	auto lat_ddegrees = geo::functions::get_decimal_degrees(dms_lat);
	auto lon_ddegrees = geo::functions::get_decimal_degrees(dms_lon);

	// Expected Results LAT 37.31917 LON -122.04511
	ASSERT_NEAR(lat_ddegrees, 37.31917, 0.00001);
	ASSERT_NEAR(lon_ddegrees, -122.04511, 0.00001);
}

TEST(Functions, GetDecimalDegrees2)
{
	// 75 59 32.483 W
	geo::DMS dms_lat{75,59,32.483, false};

	auto lat_ddegrees = geo::functions::get_decimal_degrees(dms_lat);

	// Decimal degrees: -75.9923564
	//ASSERT_DOUBLE_EQ(lat_ddegrees, -75.9923564);
	ASSERT_NEAR(lat_ddegrees, -75.9923564, 0.00001);
}

TEST(Functions, Compare)
{
	//ASSERT_TRUE(geo::functions::compare(5.13456, 5.3889, 0));
	ASSERT_FALSE(geo::functions::compare(5.13456, 5.3889, 1));

	ASSERT_TRUE(geo::functions::compare(-13.331288, -13.331267, 4));
	ASSERT_FALSE(geo::functions::compare(-13.331288, -1.331288, 4));
	ASSERT_FALSE(geo::functions::compare(-13.331288, -13.331267, 5));

	ASSERT_TRUE(geo::functions::compare(1.32146881, 1.32146891, 6));
	ASSERT_FALSE(geo::functions::compare(1.32146881, 1.32146891, 7));

	// TODO
	//ASSERT_TRUE(geo::functions::compare(5.3312, 5.3312, 10));
	//ASSERT_FALSE(geo::functions::compare(5.3312, 5.3312, 11));

	ASSERT_FALSE(geo::functions::compare(13.331288, -13.331267, 4));
	ASSERT_FALSE(geo::functions::compare(-13.331288, 13.331267, 4));
}

TEST(Functions, CompareWithBadPrecision)
{
	// TODO
}

TEST(Functions, GetDMS)
{
	// TODO
}