/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <ogre/OgrePrerequisites.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/lektor.h>

class LocationNode;
class UsageNode;

class NodeList
{
public:
	Ogre::map<hand, Ogre::vector<LocationNode*>::type>::type _0x0;
	Ogre::map<hand, Ogre::vector<UsageNode*>::type>::type _0x28;
	Ogre::map<hand, Ogre::vector<LocationNode*>::type>::type _0x50;
	class ShownNode
	{
	public:
		Ogre::Entity* _0x0;
		LocationNode* _0x8;
	};
	lektor<ShownNode*> _0x78;
	Ogre::vector<UsageNode*>::type _0x90;
	Ogre::InstanceManager* _b0;

private:

};
