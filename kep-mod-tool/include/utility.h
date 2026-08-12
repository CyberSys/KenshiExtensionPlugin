/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <kenshi/GameData.h>
#include <kep/translation.h>

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

	inline int getLevel(int rarity)
	{
		switch (rarity) {
		case 0:
			return 5;
		case 2:
			return 40;
		case 3:
			return 60;
		case 4:
			return 80;
		case 5:
			return 95;
		}
		return 20;
	}

	namespace tools
	{
		struct LessGameData
		{
			bool operator()(const GameData* a, const GameData* b) const
			{
				int result = KEP::TranslationUtility::getCollator().compare(boost::locale::collator_base::secondary, a->name, b->name);
				if (result != 0)
					return result < 0;
				return a->stringID < b->stringID;
			}
		};

		const std::string& getModulePath();
	}
}

