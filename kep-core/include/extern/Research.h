/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/lektor.h>

enum itemType;
class GameData;

class ResearchItem
{
public:
	GameData* gamedata;
	float _0x8;
	int _0xc;
private:

};

class Research
{
public:
	class BuildingUpgrades
	{
	public:
		float productionMult;
		float powerOutput;
		float powerCapacity;

		BuildingUpgrades() : productionMult(1.0f), powerOutput(0), powerCapacity(0) {}
	};

	size_t _0x0;
	int techLevel;
	Ogre::map<itemType, lektor<GameData*>>::type _0x10;
	Ogre::deque<ResearchItem>::type researchQue;
	Ogre::map<GameData*, BuildingUpgrades>::type buildingUpgradeResearchs;
	Ogre::map<std::string, Ogre::vector<ResearchItem>::type>::type _0x98;
	lektor<std::string> _0xc0;
	lektor<std::string> paid;
	ogre_unordered_set<GameData*>::type finished;
	ogre_unordered_set<GameData*>::type _0x130;
	int maxTechLevel;
	int _0x174;
	float _0x178;
};