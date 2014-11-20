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
		Logger::log("Font manager is cleaning up fonts.");
		for(std::unordered_map<std::string, Font*>::iterator it = fonts.begin();
				it != fonts.end(); it++) { it->second->close(); }
	}

	void FontManager::addFont(const std::string id, const std::string file, const int ptsize)
	{
		Font* f = new Font(file, ptsize);
		fonts[id] = f;
		
		Logger::log("Added font from file: " + file + ".");
	
		return;
	}

	Font* FontManager::getFont(const std::string id)
	{
		return fonts[id];
	}
}
