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
		class SpawnTool;
		class StatsTool;
		class PlatoonTool;
		class GamePlayOptionsTab;

		class DevToolsPanel
		{
		public:
			static DevToolsPanel* getSingletonPtr();
			static bool initialized();
			DevToolsPanel();
			~DevToolsPanel();

			void create();
			void refresh();
			void show();
			void hide();
			bool isVisible();
			SpawnTool* getSpawnTool() const { return _spawnTool; };
			StatsTool* getStatsTool() const { return _statsTool; };
			PlatoonTool* getTaskTool() const { return _platoonTool; };
			GamePlayOptionsTab* getGamePlayOptionsTab() const { return _gamePlayOptionsTab; };

		private:
			void _addMoney(DataPanelLine* line);
			void _takeMoney(DataPanelLine* line);
			void _teleportTheSelected(DataPanelLine* line);
			void _completeResearch(DataPanelLine* line);
			void _completeAllResearch(DataPanelLine* line);
			void _completeBuilding(DataPanelLine* line);
			void _completeAllBuilding(DataPanelLine* line);
			void _discoverAllTowns(DataPanelLine* line);
			void _unlockCage(DataPanelLine* line);
			void _freeTheSelected(DataPanelLine* line);
			void _healTheSelected(DataPanelLine* line);
			void _squishTheSelected(DataPanelLine* line);
			void _amputate(DataPanelLine* line);
			void _joinLimb(DataPanelLine* line);
			void _destroyTheSelected(DataPanelLine* line);
			void _editTheSelected(DataPanelLine* line);
			void _confirmEditTheSelected(int c);
			void _showRoadsOnMap(DataPanelLine* line);
			void _toggleInformationPanel(DataPanelLine* line);

			DatapanelGUI* _panel;
			const int _category;
			SpawnTool* _spawnTool;
			StatsTool* _statsTool;
			PlatoonTool* _platoonTool;
			GamePlayOptionsTab* _gamePlayOptionsTab;
			float _cats;
			int _squishParts;
			float _damageCut;
			float _damageBlunt;
			float _damagePierce;
			float _damageBleedMult;
			float _damageArmourPenetration;
			int _dismembermentLimb;

			void setButton(const std::string& caption, int cat, float width, void (DevToolsPanel::* callback)(DataPanelLine*));
			void setDropBox(const std::string& caption, int cat, float width, int* valPtr, void (DevToolsPanel::* callback)(DataPanelLine*));
			void setEditBox(const std::string& caption, int cat, float width, const std::string& text, void (DevToolsPanel::* callback)(DataPanelLine*));
		};
	}
}
