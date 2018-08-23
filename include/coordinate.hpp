/**
**	GEO C++ Library - Copyright 2018.
**	@author: Justin Carr
*/
#ifndef GEO_COORDINATE_HPP
#define GEO_COORDINATE_HPP

#include <string>
#include "dms.hpp"

namespace geo {

	/** Enumeration that represents the direction (N=North, S=South, 
	**	E=East, W=West) of geographic coordinate.
	*/
	enum class Direction { N, S, E, W };

	/*! Abstract class that represents the base of 
	**	geographic coordinate (Latitude or Longitude). 
	*/
	class Coordinate
	{
	public:

		/* Default destructor for inheritance. */
		virtual ~Coordinate() noexcept = default;

		/* Returns the decimal degrees of the coordinate. */
		virtual double decimal_degrees() const;

		/* Returns the degrees-minutes-seconds of the coordinate. */
		virtual DMS dms() const;

		/* Returns the direction value of the coordinate. */
		virtual Direction direction() const = 0;

		/* Returns the degrees-minutes-seconds string value of the coordinate. */
		virtual std::string to_string();

	protected:

		/* Ctr that initializes the class with decimal degrees. 
		* @param ddegrees: A double that represents a decimal degrees value.
		*/
		Coordinate(double ddegrees);

		/* Ctr that initializes the class with decimal degrees.
		* @param dms: A structure that represents a degrees-minutes-seconds value.
		*/
		Coordinate(const DMS & dms);

	private:

		// Decimal degrees of the coordinate.
		const double _ddegrees;

		static bool is_positive_dir(Direction dir);

		static std::string get_dir_string(Direction dir);
	};
}

#endif // !GEO_COORDINATE_HPP
