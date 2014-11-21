#include "FontManager.h"

namespace hm
{
	FontManager* FontManager::instance = nullptr;

	FontManager::FontManager()
	{
		Logger::log("Font manager started.");
	}

	FontManager::~FontManager()
	{
		if(fonts.size() > 0)
		{
			for(std::unordered_map<std::string, Font*>::iterator it = fonts.begin();
					it != fonts.end(); it++) { it->second->close(); }
				fonts.clear();
		}
	}

	void FontManager::addFont(const std::string id, const std::string file, const int ptsize)
	{
		Font* f = new Font(file, ptsize);
		fonts[id] = f;
		
	
		return;
	}

	Font* FontManager::getFont(const std::string id)
	{
		return fonts[id];
	}
}
