/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <boost/functional/hash.hpp>

#include <kenshi/util/hand.h>

#include <UtilityFunction.h>

std::size_t hash_value(const hand& h) {
	if (h.type == NULL_ITEM)
		return 0x9e3779c4;

	std::size_t seed = 0;
	boost::hash_combine(seed, h.container);
	boost::hash_combine(seed, h.index);
	boost::hash_combine(seed, h.serial);
	boost::hash_combine(seed, h.containerSerial);
	boost::hash_combine(seed, h.type);
	return seed;
}
