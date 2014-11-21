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
		closeAll();
	}

	void FontManager::open(const std::string id, const std::string file, const int ptsize)
	{
		Font* f = new Font(file, ptsize);
		fonts[id] = f;
	
		return;
	}

	void FontManager::close(const std::string id)
	{
		delete fonts[id];
		fonts[id] = nullptr;
		fonts.erase(id);
		return;
	}

	void FontManager::closeAll()
	{
		for(std::unordered_map<std::string, Font*>::iterator it = fonts.begin();
				it != fonts.end(); it++) { it->second->close(); }
		fonts.clear();

		return;
	}

	Font* FontManager::getFont(const std::string id)
	{
		return fonts[id];
	}

	std::vector<std::string> FontManager::getOpenFontIds()
	{
		std::vector<std::string> ids;
		for(std::unordered_map<std::string, Font*>::iterator it = fonts.begin();
				it != fonts.end(); it++) { ids.push_back(it->first); }
		
		return ids;
	}

	unsigned int FontManager::getNumberOfOpenFonts()
	{
		return fonts.size();
	}

	Font* FontManager::operator[](const std::string& id)
	{
		return fonts[id];
	}
}
