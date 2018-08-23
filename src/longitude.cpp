#include "longitude.hpp"
#include <stdexcept>

namespace geo {

	Longitude::Longitude(double ddecimal)
		:Coordinate(ddecimal)
	{
		if (ddecimal > 180.0 || ddecimal < -180.0)
		{
			throw std::invalid_argument("Degree decimal has to be between +180 and -180 degrees");
		}
	}

	Longitude::Longitude(const DMS & dms)
		:Coordinate(dms)
	{
	}

	Direction Longitude::direction() const
	{
		if (decimal_degrees() < 0)
		{
			return Direction::W;
		}

		return Direction::E;
	}
}