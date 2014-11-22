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
}
