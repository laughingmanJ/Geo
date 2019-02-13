#ifndef GEO_FUNCTIONS_HPP
#define GEO_FUNCTIONS_HPP

#define _USE_MATH_DEFINES

#include <math.h>
#include "dms.hpp"

namespace geo {

	namespace functions
	{
		/* Converts degrees-minutes-seconds (DMS) to decimal degrees. 
		* @param dms: A degrees-minutes-seconds struct.
		* @returns: A double that represents decimal degrees. 
		*/
		double get_decimal_degrees(DMS const &dms);


		bool compare(double value1, double value2, int precision);

		DMS get_dms(double ddegrees);

		inline double degrees_to_radians(double angle)
		{
			return M_PI * angle / 180.0;
		}
	}
}

#endif // !GEO_FUNCTIONS_HPP
