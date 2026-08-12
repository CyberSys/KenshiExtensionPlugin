/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include "config_manager.h"

namespace KEP
{
	class DECLSPEC CoreOption : public IPluginOption
	{
	public:
		CoreOption();
		virtual ~CoreOption();
		virtual void save() const;
		virtual void create(DatapanelGUI* panel, int category, ToolTip* tooltip);

		void init(const std::string& path);
		void loadSettings(const std::string& path);

		bool getEnablePlugin() const;
		bool getEnablePatchSystem() const;

	private:
		std::string _path;
		bool _isEnabledPlugin;
		bool _patchSystem;
	};

	extern DECLSPEC CoreOption coreOptions;
}