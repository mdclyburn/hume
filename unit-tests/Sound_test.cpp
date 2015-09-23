#include "catch.hpp"
#include <iostream>
#include <string>

#include "audio/Sound.h"

const std::string sound_file = "sound.wav";

TEST_CASE("Initial value(s) in Sound", "[Sound]")
{
	Sound* sound = new Sound();

	// volume should be at max
	CHECK(sound->get_volume() == 100);

	delete sound;
}

TEST_CASE("Opening sound chunk", "[Sound]")
{
	const int SDL_Init_result = SDL_Init(SDL_INIT_EVERYTHING);
	REQUIRE(SDL_Init_result == 0);
	Sound* sound = new Sound();
	REQUIRE(sound != nullptr);
	
	SECTION("once w/o close")
	{
		sound->open(sound_file);
		CHECK(sound->get_sound() != nullptr);
	}
	SECTION("once")
	{
		sound->open(sound_file);
		REQUIRE(sound->get_sound() != nullptr);

		sound->close();
		CHECK(sound->get_sound() == nullptr);
	}
	SECTION("twice")
	{
		for(unsigned int i = 0; i < 2; i++)
		{
			sound->open(sound_file);
			REQUIRE(sound->get_sound() != nullptr);

			sound->close();
			CHECK(sound->get_sound() == nullptr);
		}
	}
	SECTION("thrice")
	{
		for(unsigned int i = 0; i < 3; i++)
		{
			sound->open(sound_file);
			REQUIRE(sound->get_sound() != nullptr);

			sound->close();
			CHECK(sound->get_sound() == nullptr);
		}
	}

	delete sound;
	SDL_Quit();
}
