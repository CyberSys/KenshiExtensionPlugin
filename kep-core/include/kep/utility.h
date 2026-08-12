/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include "common.h"
#include <string>

namespace MyGUI
{
	struct Colour;
}

namespace KEP
{
	DECLSPEC const std::string& getPluginPath();

	namespace GUIColor
	{
		void init(unsigned int platform, const std::string& version, uintptr_t baseAddr);
		DECLSPEC const std::string& getMain();
		DECLSPEC const std::string& getSecondary();
		DECLSPEC const std::string& getTitle();
		DECLSPEC const std::string& getBad();
		DECLSPEC const std::string& getBadBright();
		DECLSPEC const std::string& getGood();
		DECLSPEC const std::string& getGoodBright();
		DECLSPEC const std::string& getGreyed();
		DECLSPEC const std::string& getGreyedBright();
		DECLSPEC const std::string& getSpecial();
		DECLSPEC const MyGUI::Colour& getNameTagSelected();
		DECLSPEC const MyGUI::Colour& getNameTagUnselected();
		DECLSPEC const MyGUI::Colour& getNameTagStealthHidden();
		DECLSPEC const MyGUI::Colour& getNameTagStealthAlmostSeen();
		DECLSPEC const MyGUI::Colour& getTagStealthSeen();
		DECLSPEC const MyGUI::Colour& geDialogueBubbleText();
	}

#ifdef KEPCORE_EXPORTS
	void initialize();
#endif
}
