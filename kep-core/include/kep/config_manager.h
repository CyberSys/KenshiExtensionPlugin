/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <vector>
#include "common.h"

class OptionsWindow;
class DatapanelGUI;
class ToolTip;

namespace KEP
{
	class DECLSPEC IPluginOption
	{
	public:
		virtual ~IPluginOption();
		virtual void save() const = 0;
		virtual void create(DatapanelGUI* panel, int category, ToolTip* tooltip) = 0;
	};

	class ConfigManager
	{
	public:
		static void initHook();
		DECLSPEC static ConfigManager& getSingleton();
		DECLSPEC void addItem(IPluginOption* option);
		void create(OptionsWindow* win);
		void save(OptionsWindow* win) const;

	private:
		ConfigManager();
		~ConfigManager();

		std::vector<IPluginOption*> options;
		int category;
	};
}
