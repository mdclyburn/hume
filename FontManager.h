#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <unordered_map>
#include <string>

#include "Font.h"

namespace hm
{
	class FontManager
	{
		public:
			~FontManager();

			void open(const std::string id, const std::string file, const int ptsize = 16);
			void close(const std::string id);
			void closeAll();

			Font* getFont(const std::string id);
			vector<std::string> getOpenFontIds();

			unsigned int getNumberOfOpenFonts();

			Font* operator[](const std::string& id);

			static FontManager* getInstance()
			{
				if(!instance)
					instance = new FontManager();
				return instance;
			}

			static void destroy()
			{
				if(instance)
				{
					delete instance;
					instance = nullptr;
				}
				return;
			}
			
		private:
			std::unordered_map<std::string, Font*> fonts;

			static FontManager* instance;

			FontManager();
			FontManager(const FontManager&);
			
			void operator=(const FontManager&);
	};
}

#endif
