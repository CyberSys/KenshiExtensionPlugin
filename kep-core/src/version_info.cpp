/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include "pch.h"
#include <ogre/OgreStringConverter.h>
#include <kep/version_info.h>

KEP::VersionInfo::VersionInfo()
	: major(0)
	, minor(0)
	, micro(0)
{
}

KEP::VersionInfo::VersionInfo(int _major, int _minor, int _micro)
	: major(_major)
	, minor(_minor)
	, micro(_micro)
{
}

bool KEP::VersionInfo::operator<(const VersionInfo& other) const
{
	if (major != other.major)
		return major < other.major;
	else if (minor != other.minor)
		return minor < other.minor;
	else
		return micro < other.micro;
}

bool KEP::VersionInfo::operator>(const VersionInfo& other) const
{
	return !(*this < other);
}

bool KEP::VersionInfo::operator<=(const VersionInfo& other) const
{
	if (major != other.major)
		return major <= other.major;
	else if (minor != other.minor)
		return minor <= other.minor;
	else
		return micro <= other.micro;
}

bool KEP::VersionInfo::operator>=(const VersionInfo& other) const
{
	return !(*this <= other);
}

bool KEP::VersionInfo::operator==(const VersionInfo& other) const
{
	return *this <= other && *this >= other;
}

bool KEP::VersionInfo::operator!=(const VersionInfo& other) const
{
	return !(*this == other);
}

std::string KEP::VersionInfo::toString() const
{
	return Ogre::StringConverter::toString(major) + "." + Ogre::StringConverter::toString(minor) + "." + Ogre::StringConverter::toString(micro);
}
