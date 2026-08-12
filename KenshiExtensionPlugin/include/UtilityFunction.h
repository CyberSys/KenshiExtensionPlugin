/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <sstream>

namespace KEP
{
	inline float lerp(float t, float a, float b)
	{
		return (b - a) * t + a;
	}

	inline float linear(float t, float zero, float one)
	{
		return (t - zero) / (one - zero);
	}

	inline float clamp(float a, float min, float max)
	{
		if (max <= a)
			a = max;
		if (a <= min)
			a = min;
		return a;
	}

	inline std::string getHexString(size_t number, int width)
	{
		std::stringstream ss;
		ss.setf(std::stringstream::hex);
		ss << std::hex;
		ss.width(width);
		ss.fill('0');
		ss << number;
		return ss.str();
	}

	inline std::string getHexString(void* ptr)
	{
		return getHexString(reinterpret_cast<uintptr_t>(ptr), 0x10);
	}
}

class hand;
std::size_t hash_value(const hand& h);
