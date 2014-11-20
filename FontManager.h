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

			void addFont(const std::string id, const std::string file, const int ptsize);
			Font* getFont(const std::string id);

			static FontManager* getInstance()
			{
				if(!instance)
					instance = new FontManager();
				return instance;
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
