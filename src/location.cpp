#include "location.hpp"

namespace geo {


	Latitude const & Location::latitude() const
	{
		return _latitude;
	}

	Longitude const & Location::longitude() const
	{
		return _longitude;
	}

	Elevation const & Location::elevation() const
	{
		return _elevation;
	}
}