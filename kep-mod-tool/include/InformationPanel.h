/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <string>
#include <ogre/OgrePrerequisites.h>
#include <ogre/OgreFastArray.h>
#include <kenshi/util/hand.h>

class GameData;
class DatapanelGUI;
class DataPanelLine;
class DataPanelLine_TextEditable;
class DataPanelLine_DropBox;

namespace KEP
{
	namespace tools
	{
		class InformationPanel
		{
		public:
			static InformationPanel* getSingletonPtr();
			static bool initialized();
			InformationPanel();

			void create();
			void refresh();
			void show();
			void hide();
			bool isVisible();

		private:
			void _displayBuildingInformation();
			void _displayCharacterInformation();
			void _displayCombatInformation();
			void _displayUniqueNpcInformation();

			DatapanelGUI* _panel;
			hand _lastSelected;
		};
	}
}