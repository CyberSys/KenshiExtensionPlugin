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

enum StatsEnumerated;
class GameData;
class DatapanelGUI;
class DataPanelLine;
class DataPanelLine_TextEditable;
class DataPanelLine_DropBox;

namespace KEP
{
	namespace tools
	{
		class StatsTool
		{
		public:
			StatsTool();
			int getCategory() const { return _category; }
			void setPanel(DatapanelGUI* panel) { _panel = panel; };
			void refresh();

		private:
			void _increaseStats(DataPanelLine* line);
			void _overwriteStats(DataPanelLine* line);
			void _setSlaveState(DataPanelLine* line);
			void _changePersonality(DataPanelLine* line);
			void _changePortraitSerial(DataPanelLine* line);

			void _initStatsEnumList();
			void _initStatsDataList();
			void _updateStatsEnumList();
			void _updateStatsDataList();
			void _updateSlaveSateList();
			void _updatePersonalityList();

			DatapanelGUI* _panel;
			const int _category;
			Ogre::FastArray<StatsEnumerated> _statsEnumList;
			Ogre::FastArray<GameData*> _statsDataList;
			int _selectedStatsEnum;
			int _selectedStatCategory;
			float _amount;
			float _xp;
			int _selectedStatsData;
			int _selectedSlaveState;
			int _selectedPersonality;
			float _portraitYaw;
			float _portraitPitch;

		};
	}
}