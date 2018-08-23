#ifndef GEO_LONGITUDE_HPP
#define GEO_LONGITUDE_HPP

#include "coordinate.hpp"

namespace geo {

	class Longitude : public Coordinate
	{
	public:

		Longitude(double ddecimal);

		Longitude(const DMS & dms);

		virtual Direction direction() const override;
	};
}

#endif //!GEO_LONGITUDE_HPP