#include "UnitTest.h"

#include "core/Timer.h"

const unsigned int delay = 50;
const unsigned int tolerance = 7;

TEST_CASE("Initial value(s) in Timer", "[Timer]")
{
    Timer timer;

    SECTION("after creation")
    {
	REQUIRE(timer.get_elapsed_time() == 0);
    }
    SECTION("after some time")
    {
	SDL_Delay(delay);
	REQUIRE(timer.get_elapsed_time() == 0);
    }
}

TEST_CASE("Reset Timer", "[Timer]")
{
    Timer timer;
 
    SECTION("when not running")
    {
	timer.reset();
	REQUIRE(timer.get_elapsed_time() == 0);
    }
    SECTION("when running")
    {
	timer.start();
	SDL_Delay(delay);
	REQUIRE(timer.get_elapsed_time() > 0);
	timer.reset();
	REQUIRE(timer.get_elapsed_time() < delay);
    }
    SECTION("when paused")
    {

	timer.start();
	SDL_Delay(delay);
	REQUIRE(timer.get_elapsed_time() > 0);
	timer.pause();
	timer.reset();
	REQUIRE(timer.get_elapsed_time() == 0);
    }
    SECTION("while running")
    {
	timer.start();
	SDL_Delay(delay * 5);
	REQUIRE(timer.get_elapsed_time() > 0);
	timer.reset();
	REQUIRE(timer.get_elapsed_time() < (delay * 5));
    }
}

TEST_CASE("Pause Timer", "[Timer]")
{
    Timer timer;

    SECTION("after starting")
    {
	timer.start();
	SDL_Delay(delay);
	timer.pause();
	const unsigned int elapsed = timer.get_elapsed_time();
	SDL_Delay(delay);
	REQUIRE(timer.get_elapsed_time() == elapsed);
    }
}
