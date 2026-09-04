/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include <ogre/OgreStringConverter.h>

#include <kenshi/Kenshi.h>
#include <core/Functions.h>
#include <Debug.h>

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/KingOfRenderThread.h>
#include <kenshi/PlayerInterface.h>
#include <kenshi/Research.h>

#include <kep/functions.h>
#include <Settings.h>
#include <ResearchEx.h>

namespace
{
	void (*Research_upgradeShit_orig)(Research*, GameData*);
	void Research_upgradeShit_hook(Research* self, GameData* gameData)
	{
		if (!KEP::settings._fixBuildingImprovements)
		{
			Research_upgradeShit_orig(self, gameData);
			return;
		}

		lektor<GameData*> improveBuildings;
		gameData->getAllFromListAsDatas("improve buildings", improveBuildings, &ou->gamedata, BUILDING);

		for (auto it = improveBuildings.begin(); it != improveBuildings.end(); ++it)
		{
			auto& buidingUpgrade = self->buildingUpgrades[*it];
			buidingUpgrade.productionMult *= gameData->fdata["production mult"];
			buidingUpgrade.powerBoost += gameData->idata["power increase"];
			buidingUpgrade.powerCapacity += gameData->idata["power capacity increase"];
		}
	}

	void (*Research__createBlueprintsFor_orig)(Research*, GameData*);
	void Research__createBlueprintsFor_hook(Research* self, GameData* from)
	{
		const auto idSuffix = ".TECH.1";
		auto data = ou->gamedata.getData(from->stringID + idSuffix, RESEARCH);
		if (data != nullptr)
			return;

		Research__createBlueprintsFor_orig(self, from);

		data = ou->gamedata.getData(from->stringID + idSuffix, RESEARCH);
		if (!KEP::settings._researchEx || data == nullptr)
			return;

		auto blueprintItem = from->getFromListAsData("blueprint item", 0, &ou->gamedata, ITEM);
		if (blueprintItem != nullptr)
		{
			data->objectReferences["blueprint item"].clear();
			data->addToList("blueprint item", blueprintItem->stringID, 0, 0, 0);
		}

		auto researcRequirements = from->getReferenceListIfExists("requirements");
		if (researcRequirements != nullptr)
		{
			for (auto iter = researcRequirements->begin(); iter != researcRequirements->end(); ++iter)
			{
				auto dat = iter->getPtr(&ou->gamedata);
				if (dat != nullptr && dat->type == RESEARCH)
					data->addToList("requirements", iter->sid, iter->values.value[0], 0, 0);
			}
		}

		lektor<GameData*> gearRequirements;
		from->getAllFromListAsDatas("armour requirements", gearRequirements, &ou->gamedata, ARMOUR);
		from->getAllFromListAsDatas("backpack requirements", gearRequirements, &ou->gamedata, CONTAINER);
		from->getAllFromListAsDatas("crossbow requirements", gearRequirements, &ou->gamedata, CROSSBOW);
		for (auto iter = gearRequirements.begin(); iter != gearRequirements.end(); ++iter)
		{
			auto dat = *iter;
			if (dat != nullptr)
				data->addToList("requirements", (*iter)->stringID + idSuffix, 0, 0, 0);
		}
	}

	bool once = false;
	void (*Research__setup_orig)(Research*);
	void Research__setup_hook(Research* self)
	{
		if (!once)
		{
			if (KEP::settings._researchEx)
			{
				lektor<GameData*> list;
				ou->gamedata.getDataOfType(list, RESEARCH);
				for (auto iter = list.begin(); iter != list.end(); ++iter)
				{
					lektor<std::string> sidList;
					(*iter)->getAllFromList("armour requirements", sidList);
					(*iter)->getAllFromList("backpack requirements", sidList);
					(*iter)->getAllFromList("crossbow requirements", sidList);
					for (auto sidIter = sidList.begin(); sidIter != sidList.end(); ++sidIter)
					{
						(*iter)->addToList("requirements", *sidIter + ".TECH.1", 0, 0, 0);
					}
				}
			}
			once = true;
		}
		Research__setup_orig(self);
	}

	void (*KingOfRenderThread_newGameWithCharEdit_orig)(KingOfRenderThread*, GameData*);
	void KingOfRenderThread_newGameWithCharEdit_hook(KingOfRenderThread* self, GameData* starter)
	{
		KingOfRenderThread_newGameWithCharEdit_orig(self, starter);
		if (KEP::settings._researchEx)
		{
			auto researchList = starter->getReferenceListIfExists("research");
			if (researchList != nullptr)
			{
				for (auto iter = researchList->begin(); iter != researchList->end(); ++iter)
				{
					int repeat = iter->values.value[0];
					for (int i = 2; i <= repeat; ++i)
					{
						auto dat = ou->gamedata.getData(iter->sid + "." + Ogre::StringConverter::toString(i), RESEARCH);
						if (dat != nullptr)
							ou->player->technology->completeResearch(dat);
					}
				}
			}

			lektor<std::string> sidList;
			starter->getAllFromList("armour research", sidList);
			starter->getAllFromList("backpack research", sidList);
			starter->getAllFromList("crossbow research", sidList);
			for (auto iter = sidList.begin(); iter != sidList.end(); ++iter)
			{
				auto dat = ou->gamedata.getData(*iter + ".TECH.1", RESEARCH);
				if (dat != nullptr)
					ou->player->technology->completeResearch(dat);
			}
		}
	}

}

void KEP::ResearchEx::init()
{
	if (KenshiLib::SUCCESS != KenshiLib::QueueHook(KenshiLib::GetRealAddress(&Research::upgradeShit), &Research_upgradeShit_hook, &Research_upgradeShit_orig))
		ErrorLog("Research::upgradeShit] could not install hook!");

	if (KenshiLib::SUCCESS != KenshiLib::QueueHook(KenshiLib::GetRealAddress(&Research::_createBlueprintsFor), &Research__createBlueprintsFor_hook, &Research__createBlueprintsFor_orig))
		ErrorLog("[Research::_createBlueprintsFor] could not install hook!");

	if (KenshiLib::SUCCESS != KenshiLib::QueueHook(KenshiLib::GetRealAddress(&Research::_setup), &Research__setup_hook, &Research__setup_orig))
		ErrorLog("[Research::_setup] could not install hook!");

	if (KenshiLib::SUCCESS != KenshiLib::QueueHook(KenshiLib::GetRealAddress(&KingOfRenderThread::newGameWithCharEdit), &KingOfRenderThread_newGameWithCharEdit_hook, &KingOfRenderThread_newGameWithCharEdit_orig))
		ErrorLog("[KingOfRenderThread::newGameWithCharEdit] could not install hook!");
}
