/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <string>
#include <ogre/OgrePrerequisites.h>

class GameData;
class DatapanelGUI;
class DataPanelLine;
class DataPanelLine_TextEditable;
class DataPanelLine_DropBox;

namespace KEP
{
	namespace tools
	{
		class GamePlayOptionsTab
		{
		public:
			GamePlayOptionsTab();
			int getCategory() const { return _category; }
			void setPanel(DatapanelGUI* panel) { _panel = panel; };
			void refresh();
			bool useLevelEditorCamera() const;
			bool enableNpcInventory() const;
			bool enableFastTravelMap() const;

		private:
			void _saveSettings(DataPanelLine* line);

			void _loadJson(const std::string& path);
			void _saveJson(const std::string& path) const;

			DatapanelGUI* _panel;
			const int _category;
			std::string _settingsPath;
			bool _useLevelEditorCamera;
			bool _enableNpcInventory;
			bool _enableFastTravelMap;

		};
	}
}
