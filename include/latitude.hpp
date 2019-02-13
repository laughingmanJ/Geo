#ifndef GEO_LATITUDE_H
#define GEO_LATITUDE_H

#include "coordinate.hpp"
	
namespace geo {

	class Latitude: public Coordinate
	{
	public:

		Latitude(double ddecimal);

		Latitude(const DMS & dms);

		/* Copy constructor. */
		Latitude(Latitude& other);

		/* Default destructor for inheritance. */
		virtual ~Latitude() noexcept = default;

		virtual Direction direction() const override;

		bool operator==(const Latitude &other) const;

		bool operator!=(const Latitude &other);
	};
}

#endif //!GEO_LATITUDE_H
