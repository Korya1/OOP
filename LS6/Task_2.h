#pragma once
#include "Common.h"

struct endll
{
	friend std::ostream& operator << (std::ostream& out, endll obj);
};

std::ostream& operator << (std::ostream & out, endll obj)
{
	out << "\n\n" << std::flush;
	return out;
};