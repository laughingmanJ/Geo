#ifndef GEO_LOCATION_HPP
#define GEO_LOCATION_HPP

#include "latitude.hpp"
#include "longitude.hpp"
#include "elevation.hpp"

namespace geo {

	class Location
	{
	public:

		Latitude const & latitude() const;

		Longitude const & longitude() const;

		Elevation const & elevation() const;

	private:

		Latitude _latitude;

		Longitude _longitude;

		Elevation _elevation;
	};
}

#endif // !GEO_LOCATION_HPP
