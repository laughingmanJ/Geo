#include "functions.hpp"
#include <cmath>
#include <stdexcept>

namespace geo {

	namespace functions {

		// Constant for 60 minutes in 1 degree.
		constexpr double Minutes_in_degree = 60.0;

		// Constant for 3600 seconds in 1 degree.
		constexpr double Seconds_in_degree = 3600.0;


		double get_decimal_degrees(DMS const &dms)
		{
			// Degrees + ((Minutes / 60) + (Seconds / 3600))
			double min = static_cast<double>(dms.minutes) / Minutes_in_degree;
			double sec = static_cast<double>(dms.seconds) / Seconds_in_degree;
			double ddecimal = dms.degrees + min + sec;

			return dms.pos ? ddecimal : -(ddecimal);
		}

		bool compare(double value1, double value2, int precision)
		{
			// IEEE 754 - double precision values standard is 15.95 decimal digits 
			// (We stick with 15 and below to be safe).
			if (precision < 1 || precision > 15)
			{
				throw std::invalid_argument("Precision must be a value between 1 and 15.");
			}

			// Ensure both values have the same sign.
			if(!(value1 * value2 >= 0.0))
			{
				return false;
			}

			// Get the absolute of both values and compare it to an epsilon value.
			constexpr int base_of_ten = 10;

			// isEqual = fabs(v1 – v2) <= epsilon
			// epsilon is 10^-precision
			auto abs = std::abs(value1 - value2);
			return abs <= std::pow(base_of_ten, -precision);
		}

		DMS get_dms(double ddegrees)
		{
			DMS dms;

			dms.pos = (ddegrees > 0.0);
			dms.degrees = static_cast<int>(ddegrees);
			dms.minutes = static_cast<int>(Minutes_in_degree * (ddegrees - dms.degrees));
			dms.seconds = Seconds_in_degree * (ddegrees - dms.degrees)
				- Minutes_in_degree * dms.minutes;

			return dms;
		}

	}
}