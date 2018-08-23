/**
	GEO C++ Libaray Copyright 2018.
	@author: Justin Carr
*/
#ifndef GEO_DMS_H
#define GEO_DMS_H

namespace geo {

	/*! Structure that represents a basic geographic coordinate of decimal-minutes-seconds. */
	struct DMS
	{
		// Degrees of DMS value.
		int degrees;

		// Minutes of DMS value.
		int minutes;

		// Seconds of DMS value.
		double seconds;

		// Represents a positive dms value (N or E) or a negative dms value (S or W).
		bool pos;
	};
}

#endif // !GEO_DMS_H
