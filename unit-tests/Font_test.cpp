#include "catch.hpp"
#include <string>

#include "gfx/Font.h"

const std::string FontFile = "font.ttf";

const unsigned int SmallFontSize = 14;
const unsigned int MediumFontSize = 24;
const unsigned int LargeFontSize = 44;

TEST_CASE("Initial value(s) in Font", "[Font]")
{
	TTF_Init();
	Font* font = new Font();
	REQUIRE(font != nullptr);

	CHECK(font->get_render_mode() == RenderMode::Blended);
	CHECK(font->get_font() == nullptr);
}

TEST_CASE("Opening and closing fonts", "[Font]")
{
	REQUIRE(TTF_Init() != -1);
	Font* font = new Font();
	REQUIRE(font != nullptr);

	SECTION("once (no closing)")
	{
		font->open(FontFile, SmallFontSize);
		REQUIRE(font->get_font() != nullptr);
	}
	SECTION("once (with close)")
	{
		font->open(FontFile, SmallFontSize);
		REQUIRE(font->get_font() != nullptr);
		font->close();
		CHECK(font->get_font() == nullptr);
	}
	SECTION("multiple times")
	{
		font->open(FontFile, SmallFontSize);
		REQUIRE(font->get_font() != nullptr);
		font->close();
		CHECK(font->get_font() == nullptr);

		font->open(FontFile, SmallFontSize);
		REQUIRE(font->get_font() != nullptr);
		font->close();
	
		font->open(FontFile, SmallFontSize);
		REQUIRE(font->get_font() != nullptr);
		font->close();
		CHECK(font->get_font() == nullptr);
	}

	TTF_Quit();
}

TEST_CASE("Resizing font", "[Font]")
{
	REQUIRE(TTF_Init() != -1);
	Font* font = new Font();
	font->open("font.ttf", SmallFontSize);
	REQUIRE(font != nullptr);

	SECTION("once")
	{
		font->set_size(MediumFontSize);
		CHECK(TTF_FontHeight(font->get_font()) < LargeFontSize);
	}
	SECTION("twice")
	{
		font->set_size(MediumFontSize);
		CHECK(TTF_FontHeight(font->get_font()) < LargeFontSize);

		font->set_size(LargeFontSize);
		CHECK(TTF_FontHeight(font->get_font()) > MediumFontSize);
	}
	SECTION("thrice")
	{
		font->set_size(MediumFontSize);
		CHECK(TTF_FontHeight(font->get_font()) < LargeFontSize);

		font->set_size(LargeFontSize);
		CHECK(TTF_FontHeight(font->get_font()) > MediumFontSize);

		font->set_size(SmallFontSize);
		CHECK(TTF_FontHeight(font->get_font()) < MediumFontSize);
	}

	TTF_Quit();
}

TEST_CASE("Setting RenderMode", "[Font]")
{
	REQUIRE(TTF_Init() != -1);
	Font* font = new Font();
	font->open("font.ttf", SmallFontSize);

	SECTION("to Solid")
	{
		font->set_render_mode(RenderMode::Solid);
		REQUIRE(font->get_render_mode() == RenderMode::Solid);
	}
	SECTION("to Shaded")
	{
		font->set_render_mode(RenderMode::Shaded);
		REQUIRE(font->get_render_mode() == RenderMode::Shaded);
	}
	SECTION("to Blended")
	{
		font->set_render_mode(RenderMode::Blended);
		REQUIRE(font->get_render_mode() == RenderMode::Blended);
	}
	SECTION("multiple times")
	{
		font->set_render_mode(RenderMode::Shaded);
		REQUIRE(font->get_render_mode() == RenderMode::Shaded);

		font->set_render_mode(RenderMode::Blended);
		REQUIRE(font->get_render_mode() == RenderMode::Blended);

		font->set_render_mode(RenderMode::Solid);
		REQUIRE(font->get_render_mode() == RenderMode::Solid);
	}

	font->close();
	TTF_Quit();
}
