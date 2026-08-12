/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <kenshi/util/hand.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/WorldEventStateQuery.h>

// KenshiLibでは未定義
class UniqueNPCManager
{
public:
	// KenshiLibでは未定義
	class UniqueCharacterState
	{
	public:
		GameData* characterTemplate;
		hand handle;
		WorldStateEnum state;
		bool playerInvolvement;

		UniqueCharacterState()
			: characterTemplate(nullptr)
			, handle()
			, state(ALIVE)
			, playerInvolvement(false)
		{

		}
	};
	ogre_unordered_map<GameData*, UniqueCharacterState>::type uniqueCharacterStates;
};
