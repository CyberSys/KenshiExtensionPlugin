/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <ogre/OgrePrerequisites.h>
#include <kenshi/Enums.h>
#include <kenshi/util/hand.h>
#include <kenshi/util/TimeOfDay.h>
#include <kenshi/util/TagsClass.h>

enum CharacterPerceptionTags_ShortTerm;
enum CharacterPerceptionTags_LongTerm;

class SubjectiveTags
{
public:
	virtual void setTagshortTerm();
	virtual void setTagLongTerm();
	TimeOfDay tagtime;
	TagsClass<CharacterPerceptionTags_LongTerm> tagLong;
	TagsClass<CharacterPerceptionTags_ShortTerm> tagShort;
	hand _0x30;
};

class Platoon;

class CharacterMemory
{
public:
	Ogre::map<hand, SubjectiveTags>::type tags;
	bool _0x28;
	Platoon* _0x30;
};
