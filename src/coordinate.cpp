#include "coordinate.hpp"
#include "functions.hpp"
#include <sstream>

namespace geo {

	Coordinate::Coordinate(double ddegrees)
		:_ddegrees(ddegrees)
	{
	}

	Coordinate::Coordinate(const DMS & dms)
		:_ddegrees(functions::get_decimal_degrees(dms))
	{
	}

	bool Coordinate::is_positive_dir(Direction dir)
	{
		if (dir == Direction::N || dir == Direction::W)
		{
			return true;
		}

		return false;
	}

	std::string Coordinate::get_dir_string(Direction dir)
	{
		switch (dir)
		{
		case geo::Direction::N:
			return "N";

		case geo::Direction::S:
			return "S";

		case geo::Direction::E:
			return "E";

		case geo::Direction::W:
			return "W";

		default:
			throw std::invalid_argument("");
		}

	}

	double Coordinate::decimal_degrees() const
	{
		return _ddegrees;
	}

	DMS Coordinate::dms() const
	{
		return functions::get_dms(_ddegrees);
	}

	std::string Coordinate::to_string()
	{
		auto d = dms();
		std::ostringstream ss;
		ss << d.degrees << "° ";
		ss << d.minutes << "' ";
		ss << d.seconds << "\" ";
		ss << get_dir_string(direction());

		return ss.str();
	}
}