#include "UnitTest.h"

#include "core/Timer.h"

const unsigned int delay = 50;
const unsigned int tolerance = 7;

TEST_CASE("Initial value(s)", "[Timer]")
{
    Timer timer;

    SECTION("immediate value")
    {
	REQUIRE(timer.get_elapsed_time() == 0);
    }
    SECTION("new object after some time")
    {
	SDL_Delay(delay);
	REQUIRE(timer.get_elapsed_time() == 0);
    }
}

TEST_CASE("Reset", "[Timer]")
{
    Timer timer;
 
    SECTION("after reset")
    {
	timer.reset();
	REQUIRE(timer.get_elapsed_time() == 0);
    }
    SECTION("after use")
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
