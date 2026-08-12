/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Copyright (C) 2025-2026 Lucius
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#pragma once
#include <string>
#include <boost/locale.hpp>
#include <boost/locale/format.hpp>

#include "common.h"

namespace KEP
{
	class TranslationUtility
	{
	public:
		static void init(unsigned int platform, const std::string& version, uintptr_t baseAddr);
		static void initHook();
		static DECLSPEC const std::string& getLanguage();
		static DECLSPEC std::string gettext_main(const char* id);
		static DECLSPEC std::string gettext_main(const boost::locale::message& msg);
		static DECLSPEC std::string format_main(const boost::locale::format& fmt);
		static DECLSPEC std::string dgettext(const char* domain, const char* id);
		static DECLSPEC std::string gettext(const char* id);
		static DECLSPEC std::string str(const std::string& domain, const boost::locale::message& msg);
		static DECLSPEC std::string format(const boost::locale::format& fmt);
		static DECLSPEC const boost::locale::collator<char>& getCollator();
		static DECLSPEC void getMessagesPath(const std::string& domain, const std::string& language, std::string& filepath);
	private:

	};

}
