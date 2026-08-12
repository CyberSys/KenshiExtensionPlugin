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

class GameData;
class DatapanelGUI;
class DataPanelLine;
class DataPanelLine_TextEditable;
class DataPanelLine_DropBox;

namespace KEP
{
	namespace tools
	{
		class PlatoonTool
		{
		public:
			PlatoonTool();
			int getCategory() const { return _category; }
			void setPanel(DatapanelGUI* panel) { _panel = panel; };
			void refresh();

		private:
			void _changeAI(DataPanelLine* line);
			void _resetAI(DataPanelLine* line);
			void _clearAllTag(DataPanelLine* line);
			void _triggerDialog(DataPanelLine* line);
			void _triggerPlayerConversation(DataPanelLine* line);
			void _lockDialog(DataPanelLine* line);
			void _unlockDialog(DataPanelLine* line);
			void _clearDialogTimers(DataPanelLine* line);
			void _clearAllDialogLocksAndUnlocks(DataPanelLine* line);

			void _changeAIPackageSearchText(DataPanelLine* line);
			void _changeDialogSearchText(DataPanelLine* line);

			void _initAIPackageList();
			void _updateAIPackageList(const std::string& keyword);
			void _initDialogList();
			void _updateDialogList(const std::string& keyword);

			DatapanelGUI* _panel;
			const int _category;
			Ogre::FastArray<GameData*> _AIPackageList;
			Ogre::FastArray<GameData*> _dialogList;
			int _selectedAIPackage;
			int _selectedDialog;

		};
	}
}
