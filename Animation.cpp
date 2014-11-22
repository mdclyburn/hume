#include "Animation.h"

namespace hm
{
	Animation::Animation()
	{
	
	}

	Animation::~Animation()
	{
	
	}

	void Animation::add(Blittable& b)
	{
		targets.push_back(&b);
		return;
	}

	void Animation::remove(Blittable& b)
	{
		for(std::vector<Blittable*>::iterator it = targets.begin(); it != targets.end(); it++)
		{
			if(*it == &b)
				targets.erase(it);
			return;
		}

		// Blittable not found.
		hm::Logger::log("Animation target removal failed. Blittable not found.");

		return;
	}

	void Animation::removeAll()
	{
		targets.clear();
		return;
	}

	int Animation::getUnits()
	{
		return units;
	}

	void Animation::setUnits(const int units)
	{
		this->units = units;
		return;
	}

	unsigned int Animation::getFrames()
	{
		return frames;
	}

	void Animation::setFrames(const unsigned int frames)
	{
		this->frames = frames;
		return;
	}

	void Animation::setAnimationSpeed(const int units, const unsigned int frames)
	{
		// Not sure what setting either or both of these values
		// to zero will do. User, be warned...
		if(units == 0 && frames == 0)
			hm::Logger::log("0 units per 0 frames animation. Probably not a good idea.", hm::WARNING);
		else if(units == 0)
			hm::Logger::log("Animation does nothing.", hm::WARNING);
		else if(frames == 0)
			hm::Logger::log("Animation pacing is at 0 frames.", hm::WARNING);

		this->units = units;
		this->frames = frames;

		return;
	}
}
