/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include "pch.h"

#include <boost/filesystem.hpp>

#include <kenshi/Globals.h>
#include <kenshi/GameWorld.h>
#include <kenshi/ModInfo.h>

#include <Debug.h>
#include <kep/config_manager.h>
#include <kep/utility.h>
#include <kep/settings.h>

namespace fs = boost::filesystem;

namespace
{
	std::string kepDirectory;

	BOOL startup(const std::string& path)
	{
		fs::path modulePath(path);
		if (!fs::exists(modulePath / "LICENSE") || !fs::exists(modulePath / "NOTICE.md"))
		{
			ErrorLog("License file not found.");
			return FALSE;
		}

		bool isKepPath = false;
		auto& mods = ou->availabelModsOrderedList;
		for (uint32_t i = 0; i < mods.size(); ++i)
		{
			if (mods[i]->name == "KenshiExtensionPlugin" && fs::equivalent(fs::path(mods[i]->path), modulePath))
			{
				isKepPath = true;
				break;
			}
		}

		if (!isKepPath)
		{
			ErrorLog("Location error.");
			return FALSE;
		}
		return TRUE;
	}
}

const std::string& KEP::getPluginPath()
{
	return kepDirectory;
}

__declspec(dllexport) void startPlugin()
{
	DebugLog("kep-core 1.2.0");

	KEP::coreOptions.init(kepDirectory + "\\kep_core_settings.json");
	if (!KEP::coreOptions.getEnablePlugin())
	{
		DebugLog("This plugin has been disabled in the settings. path: "+ kepDirectory + "\\kep_core_settings.json");
		return;
	}

	KEP::initialize();
	KEP::ConfigManager::getSingleton().addItem(&KEP::coreOptions);
	DebugLog("Installed");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		DWORD bufSize = _MAX_PATH;
		std::vector<TCHAR> buf(bufSize + 1, 0);
		if (GetModuleFileNameW(hModule, buf.data(), bufSize) != 0)
		{
			kepDirectory = fs::path(buf.data()).branch_path().string();
		}
		if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
			bufSize = MAXSHORT;
			buf.resize(static_cast<size_t>(bufSize) + 1);
			if (GetModuleFileNameW(hModule, buf.data(), bufSize) != 0)
			{
				kepDirectory = fs::path(buf.data()).branch_path().string();
			}
		}
		return startup(kepDirectory);
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
