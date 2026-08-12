/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <ogre/OgrePrerequisites.h>
#include <kenshi/util/OgreUnordered.h>

class ShopTrader;
class Inventory;
class InventorySection;
class UseableStuff;
class GameData;
enum itemType;

class InventoryManager
{
public:
	class BuildingInventoryInfo
	{
	public:
		Inventory* inventory;
		InventorySection* section;
		UseableStuff* stuff;
		itemType type;
		int lockLevel;
		float _0x20;
		ogre_unordered_set<GameData*>::type _0x28;
	};

	ShopTrader* onwer;
};
