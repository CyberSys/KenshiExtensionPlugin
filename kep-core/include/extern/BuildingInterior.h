/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <ogre/OgrePrerequisites.h>
#include <kenshi/util/OgreUnordered.h>
#include <kenshi/util/hand.h>
#include <kenshi/RootObject.h>
#include <kenshi/GameDataManager.h>

class Building;
class BuildingItemGroup;
class PhysicsCollection;

class Layout : public RootObjectContainer
{
public:
	std::string lyoutName; // 0x68
	Building* building; // 0x90
	BuildingInterior* buildingInterior; // 0x98
	bool _0xa0; // 0xa0
	Layout* exterior; // 0xa8

	virtual ~Layout();
};

class LayoutInterior : public Layout
{
public:
	virtual ~LayoutInterior();
};

class LayoutExterior : public Layout
{
public:
	virtual ~LayoutExterior();
};

class BuildingInterior
{
public:
	Building* building; // 0x0
	Ogre::Entity* interiorMask; // 0x8
	PhysicsCollection* physicsCollection; // 0x10
	size_t interiorParts; // 0x18
	size_t facotryCallback; // 0x20
	float _0x28; // 0x28
	bool enabledInterior; // 0x2c
	bool _0x2d; // 0x2d
	LayoutInterior layout; // 0x30
	bool allowAnimals; // 0xe0
	ogre_unordered_set<hand>::type furnitures; // 0xe8
	ogre_unordered_set<BuildingItemGroup*>::type buildingItemGroups; // 0x128
};

class BuildingInteriorDatasManager : public GameDataContainer
{
};