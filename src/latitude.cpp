#include "latitude.hpp"
#include "functions.hpp"

namespace geo
{
	Latitude::Latitude(double ddecimal) 
		: Coordinate(ddecimal)
	{
		if (ddecimal > 90.0 || ddecimal < -90.0)
		{
			throw std::invalid_argument("Degree decimal has to be between +90.0 and -90.0.");
		}
	}

	Latitude::Latitude(const DMS & dms)
		:Coordinate(dms)
	{
		if (dms.degrees > 90 || dms.degrees < -90)
		{
			throw std::invalid_argument("Degrees has to be between +90 and -90.");
		}
	}

	//Latitude::Latitude(Latitude& other)
	//{
	//}

	Direction Latitude::direction() const
	{
		return decimal_degrees() >= 0.0 ? Direction::N : Direction::S;
	}

	bool Latitude::operator==(const Latitude & other) const
	{
		constexpr int precision = 6;
		return functions::compare(decimal_degrees(), other.decimal_degrees(), precision);
	}

	bool Latitude::operator!=(const Latitude & other)
	{
		return decimal_degrees() != other.decimal_degrees();
	}
}